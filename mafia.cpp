#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
void delay()
{
    long long x=500000000;
    while(x--);
}
void delay1()
{
    long long x=50000000;
    while(x--);
}
int main ()
{ char player_name[100][100]={{0}};
    char role[100][100]={{0}};
    char input[50][100]={{0}};
    char killed[50][100]={{0}};
    char oil[50][100]={{0}};
    char a[100];
    char b[1][100];
    int vote[1000]={0};
    int n,z;
    bool flag =true;
    bool flag2 =true;
    bool flag3 =true;
    srand(time(0));
    delay();
    cout <<endl<<"                                           Welcome to the mafia game"<<endl<<endl;
    delay();
    cout <<"In this game, players are in the nine roles of werewolf, serial killer, villager, firefighter, guardian angel,goddess of love, faction, hunter and butler."<<endl;
    delay();
    cout <<endl <<"butler can make one of the living players tipple every night so tippled player can not do anything that night and butler can not tipple one player twice a row.butler is in fireman's team and if fireman die butler will die too."<<endl;
    delay();
    cout <<endl <<"Werewolves can eat only one living players per night."<<endl;
    delay();
    cout <<endl <<"serial killer can kill only one living players per night."<<endl;
    delay();
    cout <<endl <<"firefighter has two choices every night, the first is to oil one player and the second is to burn oiled players."<<endl<<"firefighter can oil players one by one at nights and burn those oiled players with one move at the next night."<<endl;
    delay();
    cout <<endl <<"guardian angel can save one player from death every night if guardian angel is alive. "<<endl;
    delay();
    cout <<endl <<"goddess of love makes two people fall in love with each other, if during the game one of the lovers be killed,the other will die."<<endl;
    delay();
    cout <<endl <<"                                          press s to start the game:";cin >>b[0];
    cout << endl<< "Enter the number of players: ";
    cin >> n;
    if (n<11)
        return 0;
    cout << "Enter player's name:"<<endl;
    for (int i=0;i<n;i++)
        cin >> player_name[i];

    //giving roles-------------------------------------------------------------------------------------

    z= rand()%n;
    strcpy(role[z],"Serial killer");

    while (flag==true)
    {
        z= rand()%n;
        if (role[z][0]==0)
        {
            strcpy(role[z],"Fireman");
            flag=false;
        }
    }
    while (flag==false)
    {
        z= rand()%n;
        if (role[z][0]==0)
        {
            strcpy(role[z],"Guardian angel");
            flag =true;
        }
    }
    while (flag==true)
    {
        z= rand()%n;
        if (role[z][0]==0)
        {
            strcpy(role[z],"Goddess of Love");
            flag=false;
        }
    }
    while (flag==false)
    {
        z= rand()%n;
        if (role[z][0]==0)
        {
            strcpy(role[z],"Faction");
            flag =true;
        }
    }
    while (flag==true)
    {
        z= rand()%n;
        if (role[z][0]==0)
        {
            strcpy(role[z],"Hunter");
            flag=false;
        }
    }
    while (flag==false)
    {
        z= rand()%n;
        if (role[z][0]==0)
        {
            strcpy(role[z],"Butler");
            flag=true;
        }
    }
    int m=(n-7), c=0, j=m/4,k=m-j;
    while (c<j)
    {
        z=rand()%(n-7)+7;
        if (role[z][0]==0)
        {
            strcpy(role[z],"Werewolf");
            c++;
        }
    }
    c=0;
    while (c<k)
    {
        z=rand()%n;
        if (role[z][0]==0)
        {
            strcpy(role[z],"Villager");
            c++;
        }
    } cout << endl<<"--roles"<<endl;
    for (int i=0;i<n;i++)
        cout << player_name [i]<<" is "<< role[i]<< endl;


    //that is night------------------------------------------------------------------------------
    for (int kh=0;kh<1000;kh++)
    {
        cout <<"---------------------------------------------------------------------------------";
        delay1();
        cout <<endl<<"night "<<kh+1<<endl;
        cout <<endl;

        for (int i=0;i<n;i++)
            if (strcoll(role[i],"Butler")==0)
            {
                cout <<"tipple: ";cin >>input[9];
                strcpy(a,input[9]);
                break;
            }
        int qw=-1;
        for (int i=0;i<n;i++)
            if(strcoll(input[9],player_name[i])==0 && input[9][0]!=0)

            {
                qw=i;
                break;
            }
        if(kh%2==1 && strcoll(a,input[9])==0)
            qw=-1;
        for (int i=0;i<n;i++)
            if (strcoll(role[i],"Werewolf")==0)
                if (strcoll(role[qw],"Werewolf")!=0)
                {
                    cout << "Eat: ";   cin >> input[0];
                    strcpy(killed[0],input[0]);
                    break;
                }
        for (int i=0;i<n;i++)
            if (strcoll(role[i],"Serial killer")==0)
                if (strcoll(role[qw],"Serial killer")!=0)
                {
                    cout << "Kill: ";  cin >> input[1];
                    z=strcoll(input[0],input[1]);
                    if (z!=0)
                        strcpy(killed[1],input[1]);
                    for (int i=0;i<n;i++)
                        if(strcoll(input[0],player_name[i])==0 && strcoll("Serial killer",role[i])==0)
                            for (int i=0;i<n;i++)
                            {
                                if(strcoll(input[1],player_name[i])==0 && strcoll("Werewolf",role[i])==0)
                                    killed[0][0]=0;
                            }
                }
        int hj=0;
        for (int i=0;i<n;i++)
            if (strcoll(role[i],"Fireman")==0)
                if(strcoll(role[qw],"Fireman")!=0)
                {
                    if (flag2==false)
                    {
                        for (int i=0;i<n;i++)
                            if (oil[i][0]==0)
                                hj++;
                        if (hj!=n)
                        {
                            cout << "Burn all oiled players?(y/n)";   cin >> input[3];
                            if (strcoll(input[3],"y")==0 )
                            {
                                for (int i=2;i<n+2;i++)
                                {
                                    if (strcoll(oil[i-2],input[0])!=0)
                                        strcpy(killed[i],oil[i-2]);
                                    for (int h=0;h<n;h++)
                                        if(strcoll(oil[i-2],player_name[h])==0 && strcoll("Serial killer",role[h])==0)
                                            for (int z=0;z<n;z++)
                                                if(strcoll(input[1],player_name[z])==0 && strcoll("Fireman",role[z])==0)
                                                    killed[1][0]=0;


                                }
                                for (int i=2;i<n+2;i++)
                                {
                                    if (strcoll(oil[i-2],input[0])!=0)
                                        strcpy(killed[i],oil[i-2]);
                                    for (int h=0;h<n;h++)
                                        if(strcoll(oil[i-2],player_name[h])==0 && strcoll("Werewolf",role[h])==0)
                                            for (int z=0;z<n;z++)
                                                if(strcoll(input[0],player_name[z])==0 && strcoll("Fireman",role[z])==0)
                                                    killed[0][0]=0;


                                }
                                for (int z=0;z<n;z++)
                                    oil[z][0]=0;
                            }
                        }
                    }
                    if (strcoll(input[3],"y")!=0 )
                    {
                        cout << "Oil: ";   cin >> input[2];
                        strcpy(oil[kh],input[2]);

                    }
                }
        int ty=0;
        while(kh<2)
        {
            for (int i=0;i<n;i++)
                if (strcoll(role[i],"Hunter")==0)
                    if(strcoll(role[qw],"Hunter")!=0)
                    {
                        cout << "Shoot: "; cin >> input[4];
                        for (int i=0;i<n;i++)
                        {
                            z=strcoll(input[4],player_name[i]);
                            if (z==0)
                            {
                                z=strcoll(role[i],"Faction");
                                if (z==0)
                                    for (int x=0;x<50;x++)
                                        if(strcoll(input[4],killed[x])!=0)
                                            ty++;
                                if(ty==50)
                                    strcpy(killed[n],input[4]);
                                break;
                            }
                        }
                    }
            break;
        }
        for (int i=0;i<50;i++)
            for (int x=0;x<50;x++)
                if(strcoll(killed[i],player_name[x])==0 and strcoll(role[x],"Fireman")==0)
                    for (int i=0;i<50;i++)
                        if(strcoll(role[i],"Butler")==0)
                            strcpy(killed[n+4],player_name[i]);
        if(strcoll(role[qw],"Goddess of Love")!=0)
            if(flag2==true)
            {
                cout << "Love: ";  cin >> input[6];cout <<" and  ";cin >>input[7];
            }
        int bi=0;
        for (int i=0;i<50;i++)
        {
            z=strcoll(input[6],killed[i]);
            if (z==0)
            {
                for (int x=0;x<50;x++)
                    if(strcoll(input[7],killed[x])!=0)
                        bi++;
                if(bi==50)
                    strcpy(killed[n+1],input[7]);
                flag=false;
                break;
            }
        }
        if (flag==true)
            for (int i=0;i<50;i++)
            {int bi=0;
                z=strcoll(input[7],killed[i]);
                if (z==0)
                {
                    for (int x=0;x<50;x++)
                        if(strcoll(input[6],killed[bi])!=0)
                            bi++;
                    if(bi==50)
                        strcpy(killed[n+2],input[6]);
                    break;
                }
            }
        for (int i=0;i<n;i++)
            if (strcoll(role[i],"Guardian angel")==0)
                if(strcoll(role[qw],"Guardian angel")!=0)
                { cout << "Save: ";  cin >> input[5];
                    if (strcoll(input[5],input[6])==0)
                        for (int i=0;i<50;i++)
                            if(strcoll(input[7],killed[i])==0)
                                killed[i][0]=0;
                    if (strcoll(input[5],input[7])==0)
                        for (int i=0;i<50;i++)
                            if(strcoll(input[6],killed[i])==0)
                                killed[i][0]=0;
                    for (int i=0;i<50;i++)
                    {
                        z=strcoll(input[5],killed[i]);
                        if (z==0)
                        {
                            killed[i][0]=0;
                            break;
                        }
                        z=strcoll(input[5],oil[i]);
                        if (z==0)
                        {
                            oil[i][0]=0;
                            break;
                        }
                    }
                }
        int y=0;

        for (int i=0;i<n;i++)
            if (strcoll(role[i],"Faction")==0)
                if(strcoll(role[qw],"Faction")!=0)
                {
                    cout << "Cult: ";  cin >> input[8];
                    for (int i=0;i<50;i++)
                    {
                        if(y==1)
                            break;
                        for (int x=0;x<50;x++)
                            if(strcoll(role[x],"Hunter")==0)
                                if(strcoll(input[8],player_name[x])==0)
                                {
                                    y++;
                                    break;
                                }
                        if (strcoll(input[8],killed[i])==0)
                            break;
                        z=strcoll(input[8],player_name[i]);
                        if (z==0)
                        {
                            strcpy(role[i],"Faction");
                            break;
                        }

                    }
                    break;
                }
        //result-------------------------------------------------------------------------------
        delay1();
        cout <<endl<<"--killed players"<<endl;
        for (int i=0;i<50;i++)
        {
            if (killed[i][0]!=0)
            {
                delay1();
                cout <<killed[i]<<endl;
                for (int h=0;h<n;h++)
                    if (strcoll(killed[i],player_name[h])==0)
                    {
                        for (int x=0;x<50;x++)
                            role[h][x]=0;
                        break;
                    }
            }
        }


        for (int i=0;i<n;i++)
            for (int h=0;h<n;h++)
                if (strcoll(killed[i],oil[h])==0)
                    oil[h][0]=0;

        for (int i=0;i<n;i++)
            if (strcoll(role [i],"Fireman")==0)
            {delay1();
                cout <<endl<<"--oiled players"<<endl;
                for (int i=0;i<50;i++)
                {
                    if (oil[i][0]!=0)
                    {delay1();
                        cout <<oil[i]<<endl;
                    }
                }cout << endl;
            }
        for (int i=0;i<50;i++)
            for (int h=0;h<100;h++)
                killed[i][h]=0 ;
        delay1();
        cout<<endl<<"--roles"<<endl;
        for (int i=0;i<n;i++)
        {
            if (role[i][0]==0)
            {delay1();
                cout << player_name [i]<<" : DEAD"<< endl;
            }
            else
            {delay1();
                cout << player_name [i]<<" is "<< role[i]<< endl;
            }
        }
        //winner-----------------------------------------------------------------------
        c=0;
        for (int i=0;i<n;i++)
            if (role[i][0]==0 or strcoll(role[i],"Faction")==0)
                c++;
        if (c==n)
        {
            cout <<endl <<"Faction is winner." << endl;
            return 0;
        }
        c=0;
        for (int i=0;i<n;i++)
            if (role[i][0]==0 or strcoll(role[i],"Villager")==0 or
                strcoll(role[i],"Guardian angel")==0 or strcoll(role[i],"Goddess of Love")==0
                or strcoll(role[i],"Hunter")==0)
                c++;
        if (c==n)
        {
            cout <<endl <<"Villagers and Goddess of Love and Guardian angel and Hunter are winners." << endl;
            return 0;
        }
        c=0;
        for (int i=0;i<n;i++)
            if (role[i][0]==0 or strcoll(role[i],"Fireman")==0 or strcoll(role[i],"Butler")==0)
                c++;
        if (c==n)
        {
            cout <<endl <<"Fireman and Butler are winners."<< endl;
            return 0;
        }
        c=0;
        for (int i=0;i<n;i++)
            if (role[i][0]==0 or strcoll(role[i],"Serial killer")==0)
                c++;
        if (c==n)
        {
            cout <<endl <<"Serial killer is winner."<< endl;
            return 0;
        }
        c=0;
        for (int i=0;i<n;i++)
            if (role[i][0]==0 or strcoll(role[i],"Werewolf")==0)
                c++;
        if (c==n)
        {
            cout <<endl <<"Werewolf is winner."<< endl;
            return 0;
        }
        c=0;
        int po=0;
        for (int i=0;i<n;i++)
            if(strcoll(role[i],"Werewolf")==0)
                c++;
        for (int i=0;i<n;i++)
            if(strcoll(role[i],"Serial killer")!=0 and strcoll(role[i],"Butler")!=0
                and strcoll(role[i],"Fireman")!=0 and role[i][0]!=0 and strcoll(role[i],"Werewolf")!=0)
                po++;
        if (c==po && c!=0)
        {
            cout <<endl <<"Werewolf is winner."<< endl;
            return 0;
        }


        //vote-------------------------------------------------------------------------
        int d=0;
        int lo=0;
        cout <<"---------------------------------------------------------------------------------";
        delay1();
        cout <<endl<<"day "<<kh+1<<endl;
        cout <<endl;
        for (int i=0;i<n;i++)
            if (role[i][0]!=0)
            {
                cout <<"How many players vote to " << player_name[i] <<" ? ";cin >> vote [i];
                if (vote[i]==d && d!=0)
                {

                    lo=-1;
                }
                if (vote[i]>d)
                {
                    d=vote[i];
                    lo=i;
                }
            }
        int fd=-1;
        if (strcoll(role[lo],"Fireman")==0)
            for (int i=0;i<50;i++)
                if(strcoll(role[i],"Butler")==0)
                {
                    fd=i;
                    role[fd][0]=0;
                    break;
                }
        if (lo!=-1)
            role[lo][0]=0;
        delay1();
        cout <<endl<<"--killed players"<<endl;
        delay1();
        cout << player_name[lo] << endl;
        if(fd!=-1)
            cout << player_name[fd] << endl;
        if(strcoll(player_name[lo],input[6])==0 or strcoll(player_name[fd],input[6])==0)
        {
            cout <<input[7]<<endl;
            for (int i=0;i<n;i++)
                if(strcoll(player_name[i],input[7])==0)
                    role[i][0]=0;
        }
        if(strcoll(player_name[lo],input[7])==0 or strcoll(player_name[fd],input[7])==0)
        {
            cout <<input[6]<<endl;
            for (int i=0;i<n;i++)
                if(strcoll(player_name[i],input[6])==0)
                    role[i][0]=0;
        }
        //clean killed player
        for (int i=0;i<50;i++)
            for (int h=0;h<n;h++)
                killed[i][h]=0 ;

        //view roles
        delay1();
        cout<<endl<<"--roles"<<endl;
        for (int i=0;i<n;i++)
        {
            if (role[i][0]==0)
            {delay1();
                cout << player_name [i]<<" : DEAD"<< endl;
            }
            else
            {delay1();
                cout << player_name [i]<<" is "<< role[i]<< endl;
            }
        }
        for (int i=0;i<n;i++)
            if (strcoll(role [i],"Fireman")==0)
            {delay1();
                cout <<endl<<"--oiled players"<<endl;
                for (int i=0;i<50;i++)
                {
                    if(strcoll(oil[i],player_name[lo])==0)
                        oil[i][0]=0;
                    if (oil[i][0]!=0)
                    {delay1();
                        cout <<oil[i]<<endl;
                    }
                }

            }
        for (int i=0;i<50;i++)
            for (int h=0;h<100;h++)
                if(i!=6 and i!=7)
                    input[i][h]=0;
        //winner--------------------------------------------------------------------------
        flag2=false;
        flag3=false;
        c=0;
        for (int i=0;i<n;i++)
            if (role[i][0]==0 or strcoll(role[i],"Faction")==0)
                c++;
        if (c==n)
        {
            cout <<endl <<"Faction is winner." << endl;
            return 0;
        }
        c=0;
        for (int i=0;i<n;i++)
            if (role[i][0]==0 or strcoll(role[i],"Villager")==0 or
                strcoll(role[i],"Guardian angel")==0 or strcoll(role[i],"Goddess of Love")==0
                or strcoll(role[i],"Hunter")==0)
                c++;
        if (c==n)
        {
            cout <<endl <<"Villagers and Goddess of Love and Guardian angel and Hunter are winners." << endl;
            return 0;
        }
        c=0;
        for (int i=0;i<n;i++)
            if (role[i][0]==0 or strcoll(role[i],"Fireman")==0 or strcoll(role[i],"Butler")==0)
                c++;
        if (c==n)
        {
            cout <<endl <<"Fireman and Butler are winners."<< endl;
            return 0;
        }
        c=0;
        for (int i=0;i<n;i++)
            if (role[i][0]==0 or strcoll(role[i],"Serial killer")==0)
                c++;
        if (c==n)
        {
            cout <<endl <<"Serial killer is winner."<< endl;
            return 0;
        }
        c=0;
        for (int i=0;i<n;i++)
            if (role[i][0]==0 or strcoll(role[i],"Werewolf")==0)
                c++;
        if (c==n)
        {
            cout <<endl <<"Werewolf is winner."<< endl;
            return 0;
        }c=0;
        po=0;
        for (int i=0;i<n;i++)
            if(strcoll(role[i],"Werewolf")==0)
                c++;
        for (int i=0;i<n;i++)
            if(strcoll(role[i],"Serial killer")!=0 and strcoll(role[i],"Butler")!=0
                and strcoll(role[i],"Fireman")!=0 and role[i][0]!=0 and strcoll(role[i],"Werewolf")!=0)
                po++;
        if (c==po && c!=0)
        {
            cout <<endl <<"Werewolf is winner."<< endl;
            return 0;
        }

    }

    return 0 ;
}
