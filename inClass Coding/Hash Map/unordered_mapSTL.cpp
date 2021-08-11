#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<string,string> cap;

    
    cap.insert(pair<string,string> ("India", "New Delhi"));
    cap.insert(make pair("USA", "Washington"));
    cap.insert({"Italy", "Rome"});

    cap["Brazil"] = "Rio";

    cout << "size" << cap.size() << endl;

    for( unordered_map<string, string>::iterator it = cap.begin(); it != cap.end();it++){
        cout << it->first << " " << it->second << endl;
    }

    cout << endl;

    for(pair<string, string> p : cap){
        cout << p.first << " " << p.second << endl;
    }

    for(int i =0; i < cap.bucket_count(); i++){
        cout << i  << " ";
        // iterate over the linked list
        for(auto it = cap.begin(i); it != cap.end();it ++){
            pair<string,string> p = *it;
            cout << p.first << " " << p.second << endl;
        }
    }

    cap["Brazil"] = "Rio de Janerio";

    string key = "India";
    if(cap.find(key) != cap.end()){
        // key is found in the map and
        cout << key << cap[key] << endl;
    }
    else{
        // key not found in the map
        cout<< "Key is not here " << endl;
    }

    key = "UK";
    if(cap.count(key) == 1){
        cout << key << cap[key] << endl;
    }
    else{
        // key not found in the map
        cout<< "Key is not here " << endl;
    }

    // be careful while using this as is key is not present it will be added to the unordered_map
    key= 'USA';
    if(cap[key] != ""){
        cout << key << cap[key] << endl;
    }
    else{
        // key not found in the map
        cout<< "Key is not here " << endl;
    }

    key = "UK";
    cap.erase(key);

    key = "India";
    cap.erase(key);

    cap.clear();

    unordered_map<string,int> menu = {
        {"Burger",50},
        {"Pepsi",5},
        {"Pizza",100},
       
    };

    
}