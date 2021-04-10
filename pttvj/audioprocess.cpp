#include "audioprocess.h"
#include "setting.h"
#include <QDebug>
#include <QAudioInput>
#include <QObject>
#include <QByteArray>
#include <algorithm>
AudioProcess::AudioProcess(QObject *parent) : QObject(parent)
{
    QAudioFormat format;
    // Set up the desired format, for example:
    format.setSampleRate(44100);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    this->input = new QAudioInput(format);
    this->inputDevice = this->input->start();
    QAudioInput::connect(this->inputDevice, SIGNAL(readyRead()), this, SLOT(readBuf()));

    qDebug() << "audio start";
}

void AudioProcess::readBuf(){
    QByteArray buf_byte = this->inputDevice->readAll();
    int N = buf_byte.size()/2;
    int16_t *buf = (int16_t *)buf_byte.data();
    if(N>=2048){
        for(int i=0; i<2048; i++){
            Setting::waveform[i] = buf[N-2048+i];
        }
    }else{
        for(int i=0; i<2048; i++){
            if(i<2048-N){
                Setting::waveform[i] = Setting::waveform[N+i];
            }else{
                Setting::waveform[i] = buf[i-(2048-N)];
            }
        }
    }
}
