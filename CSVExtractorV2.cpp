#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>

using namespace std;




typedef struct record{
    /* 
    direction 10
    date 11
    weekday 10
    */
    string Direction;
    string Date;
    string Weekday;
    string Country;
    string Commodity;
    string Transport_Mode;
    string Measure;
    long int Value;
    long int Cumulative;
    int Year;
    
}Record;



vector<Record> Data;


// * TODO:  STOLL INSTEAD OF STOL
void insertData(int counter, string token){
    switch (counter)
    {
    case 0: Data.back().Direction=token; break;
    case 1: Data.back().Year=stoi(token); break;
    case 2: Data.back().Date=token; break;
    case 3: Data.back().Weekday=token; break;
    case 4: Data.back().Country=token; break;
    case 5: Data.back().Commodity=token; break;
    case 6: Data.back().Transport_Mode=token; break;
    case 7: Data.back().Measure=token; break;
    case 8: Data.back().Value=stoll(token); break;
    case 9: Data.back().Cumulative=stoll(token); break;
    default:
        break;
    }
}


void splitstring(stringstream& ss){
    string token;
    int counter=0;
    while(getline(ss, token, ',')){
        //cout<<"TOKEN: "<< token<<endl;
        insertData(counter, token);
        counter++;
    }
    
}

int main(){


string line="";
stringstream ss(line);
Record* temp;
//stringstream check;
ifstream file("effects-of-covid-19-on-trade-at-15-december-2021-provisional.csv");
if(file.good()){

file>>line;
int i=1;
    while(file>>line){
            //check(line);
      //  cout<<line<<endl;
        // temp=(Record*)malloc(sizeof(Record));
        temp= new Record;
        Data.push_back(*temp);
        ss<<line;
       // cout << ss.str() << endl;
        splitstring(ss);
       //cout<<"\t"<< i++ <<line<<endl;
      // cout<<ss.str()<<endl;
       ss.str("");
       ss.clear();
       //ss.str(std::string());
    }

    // for (int  i = 0; i < Data.size(); i++)
    // {
    //     cout<<Data[i].Year<<endl;
    // }
    

    cout<<Data.back().Direction<<"\t"<<Data.back().Year<<"\t"<<Data.back().Date<<"\t"<<Data.back().Weekday<<"\t"<<
    Data.back().Country<<"\t"<<Data.back().Commodity<<"\t"<<Data.back().Transport_Mode<<"\t"<<Data.back().Measure<<"\t"<<Data.back().Value<<"\t"<<
    Data.back().Cumulative<<endl;


   // cout<<sizeof(Data.back().Country)<<endl;

}

system("pause");
    return 0;
}