from pytube import YouTube

print("URL?")

url = input()

yt = YouTube(url)

l = yt.streams.order_by('resolution')

for s in l:
    print(l.index(s)," : ",s)

print("INDEX?")
idx = int(input())

print("FILENAME?")
filename = input()

print("DOWNLOADING...")
l[idx].download("./", filename)
print("COMPLETE!")