#include <iostream>
#include <fstream>

using namespace std;
const int MAXROWS = 9;
const int MAXCOLS = 9;

//from ch 7
int find (string s, char c, int i);//find a char in a string
//from ??
int find (string array[], string s, int arrLen);//find a string in an array
//section 9.4
void processLine (string line, string& city1, string& city2, string& distString);
//section 9.5
int convertToInt (string s);
//section 9.7
void print_matrix(int matrix[][MAXCOLS]);
//section 9.8
void addDataToMatrix(string city1, string city2, string distString,
                     string cityArr[],int &numCities, int distances[][MAXCOLS]);
int main(){
    //
     string fileName = "cities.txt";
     string line;
     int distances[MAXROWS][MAXCOLS]={0};
     string cityArr[MAXROWS];
     int numCities=0;
     ifstream infile (fileName);

     if (infile.good() == false) {
         cout << "Unable to open the file named " << fileName;
         exit (1);
     }

     while (true) {
         getline (infile, line);
         if (infile.eof()) break;
         //cout << line << endl;
         string city1,city2,distString;
         processLine(line,city1,city2,distString);
         addDataToMatrix(city1,city2,distString,cityArr,numCities,distances);
     }
     //print out the matrix
     print_matrix(distances);
     //or a prettier version
     for (int i=0; i<numCities; i++) {
         for (int j=-1; j<=i; j++) {
             if (j<0){
                 cout<<cityArr[i]<<"\t";
             } else {
                 cout << distances[i][j] << "\t";
             }
        }
        cout << endl;
    }
    cout<<"\t";
    for (int i=0; i<numCities; i++){
        cout<<cityArr[i]<<"\t";
    }
    cout << endl;

}
//from ch 7
int find (string s, char c, int i) {//from ch 7
    while (i<s.length()) {
        if (s[i] == c) return i;
        i = i + 1;
    }
    return -1;
}

int find (string array[], string s, int arrLen) {
    int i=0;
    while (i<arrLen) {
        if (array[i] == s) {
            return i;
        }
        i++;
    }
    return -1;
}

void processLine (string line, string& city1, string& city2, string& distString) {
  // the character we are looking for is a quotation mark
  char quote = '\"';

  // store the indices of the quotation marks in an array
  int quoteIndex[4];

  // find the first quotation mark using the built-in find
  quoteIndex[0] = line.find (quote);

  // find the other quotation marks using the find from Chapter 7
  for (int i=1; i<4; i++) {
    quoteIndex[i] = find (line, quote, quoteIndex[i-1]+1);
  }

  // break the line up into substrings
  int len1 = quoteIndex[1] - quoteIndex[0] - 1;
  city1 = line.substr (quoteIndex[0]+1, len1);
  int len2 = quoteIndex[3] - quoteIndex[2] - 1;
  city2 = line.substr (quoteIndex[2]+1, len2);
  int len3 = line.length() - quoteIndex[2] - 1;
  distString = line.substr (quoteIndex[3]+1, len3);

  // output the extracted information
  cout << city1 << "\t" << city2 << "\t" << distString << endl;
}

void addDataToMatrix(string city1, string city2, string distString,
                     string cityArr[],int &numCities, int distances[][MAXCOLS]){
    int index1 = find(cityArr,city1,numCities);
    if (index1<0){//city not found
        index1=numCities;
        cityArr[numCities++]=city1;
    }
    int index2=find(cityArr,city2,numCities);
    if (index2<0){//city not found
        index2=numCities;
        cityArr[numCities++]=city2;
    }
    int dist = convertToInt (distString);
    distances[index1][index2] = dist;
    distances[index2][index1] = dist;
}

//section 9.5
int convertToInt (string s){
  string digitString = "";

  for (int i=0; i<s.length(); i++) {
    if (isdigit (s[i])) {
      digitString += s[i];
    }
  }
  return atoi (digitString.c_str());
}

//section 9.7
void print_matrix(int matrix[][MAXCOLS]){
    for (int row=0; row < MAXROWS; row++) {
        for (int col=0; col < MAXCOLS; col++) {
            cout << matrix[row][col] << "\t";
        }
        cout << endl;
    }
}
