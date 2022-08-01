#include<bits/stdc++.h>
#include <getopt.h>
using namespace std;
// #define rep(i,n) for(int i = 0 ; i < n ; i++);

string op = "";
string ip = "";
int flag[] = {0,0,0,0};


string upper(string s)
{

    for(int i=0;i<s.length();i++)
    {
        s[i]=toupper(s[i]);
    }
    return s;
}

string fupper(string s)
{
    s[0]=toupper(s[0]);
    return s;
}

string removeSpaces(string str){
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

void trim(vector<string>&s){

    for(int i=0;i<s.size();i++){
        s[i]=removeSpaces(s[i]);
    }
}



int main(int argc, char** argv){
    int opt;
    
    
   

    const char* const short_opts = "i:o:efc";
    const option long_opts[] = {
        {"input", required_argument, nullptr, 'i'},
        {"output", required_argument, nullptr, 'o'},
        {"envelope", no_argument, nullptr, 'e'},
        {"fixed", no_argument, nullptr, 'f'},
        {"csv", no_argument, nullptr, 'c'},
        {"matchcode", no_argument, nullptr, 'm'},
        {"nickname", no_argument, nullptr, 'n'},
        {"uppercase", no_argument, nullptr, 'u'},
        {"titlecase", no_argument, nullptr, 't'},
        {nullptr, no_argument, nullptr, 0}
    };

    while (true)
    {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (-1 == opt)
            break;

        switch (opt)
        {
        case 'i':
            ip = optarg;
            break;

        case 'o':
            op = optarg;
            break;

        case 'n':
            flag[0] = 1;
            break;

        case 'm':
           flag[1] = 1;
            break;

        case 'u': 
             flag[2] = 1;
            break;
        case 't': 
             flag[3] = 1;
            break;
        default:
        
            break;
        }
    }


    fstream new_file;
    new_file.open("sample_input.in", ios::in);
    string full_row;
    vector<string> data;
    if(!new_file.is_open())cout << "Error in opening the file";
  
    if(new_file.is_open()){
        while (getline(new_file,full_row))
        {
           
            data.push_back(full_row);
              
        }
        
    }

  
    vector<string> fname;
    vector<string> lname;
    vector<string> str_address;
    vector<string> houseno;
    vector<string> city;
    vector<string> state;
    vector<string> zip;
    vector<string> nickname;
    vector<string> midname;
    
    for(int i=0;i<data.size();i++){
       
        string my_line=data[i];
        lname.push_back(my_line.substr(0,15));
        fname.push_back(my_line.substr(15,15));
        midname.push_back(my_line.substr(30,15));
        nickname.push_back(my_line.substr(45,10));
        houseno.push_back(my_line.substr(55,5));
        str_address.push_back(my_line.substr(60,20));
        city.push_back(my_line.substr(80,15));
        state.push_back(my_line.substr(95,15));
        zip.push_back(my_line.substr(110,6));

    }
    
    trim(fname);trim(lname);
    trim(houseno);trim(str_address);trim(zip);
    trim(city);trim(state);
    trim(midname);trim(nickname);

    // for(int i = 0 ; i < fname.size() ; i++){
    //     cout << nickname[i]<<" ";
    // }
    if(op == "envelope"){
        cout<<" ENVELOPE FORMAT "<<endl;

        for(int i=0;i<fname.size();i++){

            if(flag[3]==1){

                if(flag[1]==1){

                string matchcode="";
                matchcode.push_back((str_address[i])[0]);
                matchcode.push_back((fname[i])[0]);
                matchcode = matchcode + zip[i];
                cout<<fupper(matchcode)<<" ";
            }
                if(flag[0]==1)
                cout<<fupper(nickname[i])<<" ";
                
            else
                cout<<fupper(fname[i])<<" "<<fupper(lname[i])<<" ,";
                cout<<endl<<fupper(houseno[i])<<" "<<fupper(str_address[i])<<" ,";
                cout<<endl<<fupper(city[i])<<" ,"<<fupper(state[i])<<" "<<fupper(zip[i])<<" ,";
                cout<<endl<<endl;
            
            }
            else if(flag[2]==1)
            {
                if(flag[1]==1)
            {
                string matchcode="";
                matchcode.push_back((str_address[i])[0]);
                matchcode.push_back((fname[i])[0]);
                matchcode = matchcode + zip[i];
                cout<<upper(matchcode)<<" ";
            }
                if(flag[0]==1){
                cout<<upper(nickname[i])<<" ";
                }else{
                cout<<upper(fname[i])<<" "<<lname[i]<<" ,";
                cout<<endl<<upper(houseno[i])<<" "<<upper(str_address[i])<<" ,";
                cout<<endl<<upper(city[i])<<" ,"<<upper(state[i])<<" "<<upper(zip[i])<<" ,";
                cout<<endl<<endl;
                }
            }
            else{
                    if(flag[1]==1)
            {
                string matchcode="";
                matchcode.push_back((str_address[i])[0]);
                matchcode.push_back((fname[i])[0]);
                matchcode = matchcode + zip[i];
                cout<<matchcode<<" ";
            }
            if(flag[0]==1)
            cout<<nickname[i]<<" ";
            else
            cout<<fname[i]<<" "<<lname[i]<<" ,";
            cout<<endl<<houseno[i]<<" "<<str_address[i]<<" ,";
            cout<<endl<<city[i]<<" ,"<<state[i]<<" "<<zip[i]<<" ,";
            cout<<endl<<endl;
    }
        }
    }
    
    if(op == "fixed"){
        cout<<" FIXED FORMAT"<<endl;
        
        for(int i=0;i<fname.size();i++){

            if(flag[3]==1){

                if(flag[1]==1){

                string matchcode="";
                matchcode.push_back((str_address[i])[0]);
                matchcode.push_back((fname[i])[0]);
                matchcode = matchcode + zip[i];
                cout<<fupper(matchcode)<<" ";
            }
                if(flag[0]==1)
                cout<<fupper(nickname[i])<<" ";
                
            else
                for(int i=0;i<fname.size();i++)
        {
            cout << fupper(fname[i]) << " " << fupper(lname[i]) << " " << fupper(houseno[i]) << " " << fupper(str_address[i]) << " "  << fupper(city[i]) << " " <<fupper(state[i]) << " " << fupper(zip[i]);
            cout << endl << endl;
        }
            
            }
            else if(flag[2]==1)
            {
                if(flag[1]==1)
            {
                string matchcode="";
                matchcode.push_back((str_address[i])[0]);
                matchcode.push_back((fname[i])[0]);
                matchcode = matchcode + zip[i];
                cout<<upper(matchcode)<<" ";
            }
                if(flag[0]==1){
                cout<<upper(nickname[i])<<" ";
                }else{
                cout << upper(fname[i]) << " " << upper(lname[i]) << " " << upper(houseno[i]) << " " << upper(str_address[i]) << " "  << upper(city[i]) << " " <<upper(state[i]) << " " << upper(zip[i]);
                 cout<<endl<<endl;
                }
            }
            else{
                    if(flag[1]==1)
            {
                string matchcode="";
                matchcode.push_back((str_address[i])[0]);
                matchcode.push_back((fname[i])[0]);
                matchcode = matchcode + zip[i];
                cout<<matchcode<<" ";
            }
            if(flag[0]==1)
            cout<<nickname[i]<<" ";
            else
           cout << fname[i] << " " << lname[i] << " " << houseno[i] << " " << str_address[i] << " "  << city[i] << " " <<state[i] << " " << zip[i];
            cout<<endl<<endl;
    }
        }
        for(int i=0;i<fname.size();i++)
        {
            cout << fname[i] << " " << lname[i] << " " << houseno[i] << " " << str_address[i] << " "  << city[i] << " " <<state[i] << " " << zip[i];
            cout << endl << endl;
        }
    }
    if(op == "csv"){
        cout<<" CSV FORMAT"<<endl;

        for(int i=0;i<fname.size();i++)
        {
            cout << "'"<<fname[i] << "' '" << lname[i] << "' '" << houseno[i] << "' '" << str_address[i] << "' '"  << city[i] << "' '" <<state[i] << "' '" << zip[i]<<"' '";
            cout << endl << endl;
        }
    }
    

    new_file.close();
    return 0;
   
   
        
        
}