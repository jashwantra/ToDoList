#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    char temp[20],final[100];
    final[0]='\0';
    pair<int,string> temp1;
    if(argc>1)
    {
        strcpy(temp,*(argv+1));
        if(argc>2)
        {
            stringstream s(argv[2]);
            s>>temp1.first;
        }
        if(argc>3)
        {
            for(int i=3;i<argc;i++)
            {
                char tempstring[30];
                strcpy(tempstring,argv[i]);
                strcat(final,tempstring);
                strcat(final," ");
            }
            stringstream s(final);
            getline(s,temp1.second);
        }
    }
    if(argc==1)
    {
        cout<<"Usage :-\n";
        cout<<"$ ./task add 2 hello world    # Add a new item with priority 2 and text \"hello world\" to the list\n";
        cout<<"$ ./task ls                   # Show incomplete priority list items sorted by priority in ascending order\n";
        cout<<"$ ./task del INDEX            # Delete the incomplete item with the given index\n";
        cout<<"$ ./task done INDEX           # Mark the incomplete item with the given index as complete\n";
        cout<<"$ ./task help                 # Show usage\n";
        cout<<"$ ./task report               # Statistics\n";
    }
    else if(argc==2)
    {
        if(!strcmp(temp,"help"))
        {
            cout<<"Usage :-\n";
            cout<<"$ ./task add 2 hello world    # Add a new item with priority 2 and text \"hello world\" to the list\n";
            cout<<"$ ./task ls                   # Show incomplete priority list items sorted by priority in ascending order\n";
            cout<<"$ ./task del INDEX            # Delete the incomplete item with the given index\n";
            cout<<"$ ./task done INDEX           # Mark the incomplete item with the given index as complete\n";
            cout<<"$ ./task help                 # Show usage\n";
            cout<<"$ ./task report               # Statistics\n";
        }
        else if(!strcmp(temp,"ls"))
        {
            ifstream fin;
            fin.open("task.txt");
            int n=0;
            pair<int,string> temp2;
            while(fin)
            {
                n++;
                fin>>temp2.first;
                getline(fin,temp2.second);
                if(fin.eof()) break;
                cout<<n<<". "<<temp2.second<<" ["<<temp2.first<<"]\n";
            }
            fin.close();
        }
        else if(!strcmp(temp,"report"))
        {
            ifstream fin;
            fin.open("task.txt");
            int n=0;
            vector<pair<int,string>> vec;
            pair<int,string> temp2;
            while(fin)
            {
                fin>>temp2.first;
                getline(fin,temp2.second);
                if(fin.eof()) break;
                vec.push_back(temp2);
                n++;
            }
            fin.close();
            cout<<"Pending : "<<n<<"\n";
            int counter=1;
            vector<pair<int,string>>::iterator it;
            for(it=vec.begin();it!=vec.end();it++)
            {
                cout<<counter<<". "<<(*it).second<<" ["<<(*it).first<<"]\n";
                counter++;
            }
            vec.clear();n=0;counter=1;
            fin.open("completed.txt");
            while(fin)
            {
                fin>>temp2.first;
                getline(fin,temp2.second);
                if(fin.eof()) break;
                vec.push_back(temp2);
                n++;
            }
            fin.close();
            cout<<"Completed : "<<n<<"\n";
            for(it=vec.begin();it!=vec.end();it++)
            {
                cout<<counter<<"."<<temp2.second<<"\n";
            }
        }
    }
    else
    {
        if(!strcmp(temp,"add"))
        {
            ifstream fin;
            fin.open("task.txt");
            int n=0;
            vector<pair<int,string>> vec;
            pair<int,string> temp2;
            while(fin)
            {
                fin>>temp2.first;
                getline(fin,temp2.second);
                if(fin.eof()) break;
                vec.push_back(temp2);
                n++;
            }
            fin.close();
            remove("task.txt");
            vec.push_back(temp1);
            sort(vec.begin(),vec.end());
            ofstream fout;
            fout.open("task.txt",ios::trunc|ios::out);
            vector<pair<int,string>>:: iterator it;
            for(it=vec.begin();it!=vec.end();it++)
            {
                fout<<(*it).first<<" "<<(*it).second<<"\n";
            }
            fout.close();
            cout<<"Added task:"<<temp1.second<<"with priority "<<temp1.first<<"\n";
        }
        else if(!strcmp(temp,"del"))
        {
            ifstream fin;
            fin.open("task.txt");
            int n=0;
            vector<pair<int,string>> vec;
            pair<int,string> temp2;
            while(fin)
            {
                fin>>temp2.first;
                getline(fin,temp2.second);
                if(fin.eof()) break;
                vec.push_back(temp2);
                n++;
            }
            fin.close();
            remove("task.txt");
            sort(vec.begin(),vec.end());
            vec.erase(vec.begin()+temp1.first-1,vec.begin()+temp1.first);
            ofstream fout;
            fout.open("task.txt",ios::trunc|ios::out);
            vector<pair<int,string>>:: iterator it;
            for(it=vec.begin();it!=vec.end();it++)
            {
                fout<<(*it).first<<" "<<(*it).second<<"\n";
            }
            fout.close();
            cout<<"Deleted item with index "<<temp1.first;
        }
        else if(!strcmp(temp,"done"))
        {
            ifstream fin;
            fin.open("task.txt");
            int n=0;
            vector<pair<int,string>> vec;
            pair<int,string> temp2;
            while(fin)
            {
                fin>>temp2.first;
                getline(fin,temp2.second);
                if(fin.eof()) break;
                vec.push_back(temp2);
                n++;
            }
            fin.close();
            remove("task.txt");
            sort(vec.begin(),vec.end());
            temp2=*(vec.begin()+temp1.first-1);
            vec.erase(vec.begin()+temp1.first-1,vec.begin()+temp1.first);
            ofstream fout;
            fout.open("task.txt",ios::trunc|ios::out);
            vector<pair<int,string>>:: iterator it;
            for(it=vec.begin();it!=vec.end();it++)
            {
                fout<<(*it).first<<" "<<(*it).second<<"\n";
            }
            fout.close();
            fout.open("completed.txt",ios::app|ios::out);
            fout<<temp2.second<<"\n";
            cout<<"Marked item as done.\n";
        }
        
        
    }



    return 0;
}