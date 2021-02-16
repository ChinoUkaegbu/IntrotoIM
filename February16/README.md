# Generative Text Assignment - *Call It What You Want*

## Chinonyerem Ukaegbu


**Description**

The task was to create either a data visualization or a generative text using the functions we had learnt last class.

**Inspiration**

As you probably can tell from the contents of the data set, this project was heavily inspired by Taylor Swift. In honour of the announcement she made of the anticipated release of the rerecorded versions of the songs from her album *Fearless* , I decided to base this project off the lyrics of some of her earlier songs. The visualization is titled *Call It What You Want* partly because I had no idea what to call it and also because it's a reference to a song from her album *Reputation*. 

**Process**

There were a couple of datasets with the song lyrics separated by line number, but I needed the lyrics to be represented by one value per song entry, and then I came upon the data set accessible through this link:
[Taylor Swift Dataset](https://github.com/rochelleterman/FSUtext/blob/master/02_Dictionary/taylor_swift.csv)

</br>
I needed to count the number of characters per song lyric so I first had to download the CSV file, load it up in Excel, remove the forward slashes(/) that had been used to separate each line and then use an excel formula to calculate the number of characters in each song lyric entry.
</br>
I did not need the column for the artiste's name and because each album was released in a different year, I deleted the column for album name and opted to use the column for year of release as an identifier instead.

</br>
I then created four files, one for the year of release, one for the track number, one for the length of lyrics and the last for the title of the tracks and loaded them into Processing.

```js
String year[];
String track_n[];
String lyric_length[];
String track_title[];


void setup() {
  size(1600, 1000);
  background(105, 102, 103);

  //Load files into array
  
  year = loadStrings("year.csv");
  track_n = loadStrings("track_n.csv");
  lyric_length = loadStrings("lyric_length.csv");
  track_title = loadStrings("track_title.csv");
  ```

After I decided that I wanted the data to be represented as circles, I got to work on translating the data into what I had planned in Processing. The radius of the circle increased as the length of the lyrics increased, the songs that were from the same album had the same colour and the songs that had the same track number from various albums were on the same y-axis
I did this by playing around with some values until I was ultimately satisfied with what the code looked like

```js
for ( int i = 0; i < yearData.length; i++) {
    if (yearData[i]==2006) {   //2006
      fill(255, 236, 148);
      circle(random(200, 1400), track_nData[i]+50, lyric_lengthData[i]/20);
    }
    if (yearData[i]==2008) {   //2008
      fill(255, 174, 174);
      circle(random(200, 1400), track_nData[i]+50, lyric_lengthData[i]/20);
    }
    if (yearData[i]==2010) {   //2010
      fill(143, 96, 72);
      circle(random(200, 1400), track_nData[i]+50, lyric_lengthData[i]/20);
    }
    if (yearData[i]==2012) {   //2012
      fill(176, 229, 124);
      circle(random(200, 1400), track_nData[i]+50, lyric_lengthData[i]/20);
    }
    if (yearData[i]==2014) {   //2014
      fill(180, 216, 231);
      circle(random(200, 1400), track_nData[i]+50, lyric_lengthData[i]/20);
    }
    if (yearData[i]==2017) {   //2017
      fill(86, 186, 236);
      circle(random(200, 1400), track_nData[i]+50, lyric_lengthData[i]/20);
    }
    fill(255, 255, 255);
    ```
    
    The final output looked like this:
