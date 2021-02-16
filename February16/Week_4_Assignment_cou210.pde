/*This is the Production Assignment for Week 4
 Chinonyerem Ukaegbu
 Concept:
 The program displays Taylor Swift songs from 2006 to 2017 as circles with the radius correspondong to the length of the song(lyrically), and is displayed such that 
 all songs from the same  album are denoted by the same colour and all songs that have the same track number appear along the same vertical plane
 Data source: https://github.com/rochelleterman/FSUtext/blob/master/02_Dictionary/taylor_swift.csv
 16 February, 2021
 */

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

  //printArray(year);
  //printArray(track_n);
  //printArray(lyric_length);
  //printArray(track_title);
}
void draw() {
  int yearData[];
  int track_nData[];
  int lyric_lengthData[];


  yearData = int(year);
  track_nData = int(track_n);
  lyric_lengthData = int(lyric_length);

  //Let's draw the ellipses

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

    noLoop();
    //text(track_title[i], random(200, 1400), track_nData[i]+50);
  }
}
