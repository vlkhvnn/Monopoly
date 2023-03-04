#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <cstring>
using namespace std;
// GLOBAL VARIABLES
int turnNum = 0;
int numPlayers;

void clearscreen(void)
{
    system("cls");
}
int rollDie()
{
    srand(time(0));
    return ((rand() % 11) + 2);
}
enum PlaceColor
{
    BROWN,
    SKY,
    PINK,
    ORANGE,
    RED,
    YELLOW,
    GREEN,
    BLUE,
    WHITE
};

struct Player
{
    string PlayerName;
    int PlayerNum;
    int PlayerPosition;
    int Wealth;
    bool Bankrupt;
    vector<string> OwnedProps;
    void displayStats()
    {
        cout << PlayerName << " has " << Wealth << " tenge and has " << OwnedProps.size() << " properties" << endl;
        cout << "Position on board is " << PlayerPosition <<endl;
    }
    Player(string _name = " ", int newPlayerNum = -1, int newWealth = 2000000, int _TurnInJail = 0)
    {
        *intPositionPointer = 0;
        PlayerName = _name;
        PlayerNum = newPlayerNum;
        *WealthPtr = newWealth;
        KeepBidding = false;
        Bankrupt = false;
    }
};

struct Property
{
    string PropertyName;
    int PropertyPrice;
    int Position;
    bool IsOwned;
    Player *PropertyOwner;
    bool ownAllColor; // if players owns all properties of one colour
    int SellValue;
    int RentValue;
    PlaceColor colorGroup;

    /* If the card is a chance, community chest, go, etc, it will have a special function */
    int PropertyType;

    Property(string _name = " ", int _PropertyPrice = -1, int _Position = 0, int _PropertyType = -1, int _SellValue = -1, PlaceColor _colorGroup = WHITE)
    {
        PropertyName = _name;
        Position = _Position;
        PropertyType = _PropertyType;

        SellValue = _SellValue;
        colorGroup = _colorGroup;
        ownAllColor = false;
        IsOwned = false;
    }
};

class GameBoard
{
private:
    int NumProperties;
public:
    Property GameProperties[40];
    GameBoard()
    {
        GameProperties[0].PropertyName = "Start";
        GameProperties[0].Position = 0;
        GameProperties[0].PropertyType = 4;
        GameProperties[1].PropertyName = "Lenger";
        GameProperties[1].Position = 1;
        GameProperties[1].PropertyType = 0;
        GameProperties[1].PropertyPrice = 100000;
        GameProperties[1].SellValue = 50000;
        GameProperties[1].RentValue = 20000;
        GameProperties[1].colorGroup = BROWN;
        GameProperties[2].PropertyName = "Community Chest";
        GameProperties[2].Position = 2;
        GameProperties[2].PropertyType = 3;
        GameProperties[3].PropertyName = "Khromtau";
        GameProperties[3].Position = 3;
        GameProperties[3].PropertyType = 0;
        GameProperties[3].PropertyPrice = 120000;
        GameProperties[3].SellValue = 60000;
        GameProperties[3].RentValue = 50000;
        GameProperties[3].colorGroup = BROWN;
        GameProperties[4].PropertyName = "Income Tax";
        GameProperties[4].Position = 4;
        GameProperties[4].PropertyType = 5;
        GameProperties[5].PropertyName = "Almaty-1 RailRoad";
        GameProperties[5].Position = 5;
        GameProperties[5].PropertyType = 1;
        GameProperties[5].PropertyPrice = 250000;
        GameProperties[5].SellValue = 125000;
        GameProperties[6].PropertyName = "Esik";
        GameProperties[6].Position = 6;
        GameProperties[6].PropertyType = 0;
        GameProperties[6].PropertyPrice = 150000;
        GameProperties[6].SellValue = 75000;
        GameProperties[6].RentValue = 70000;
        GameProperties[6].colorGroup = SKY;
        GameProperties[7].PropertyName = "Chance";
        GameProperties[7].Position = 7;
        GameProperties[7].PropertyType = 2;
        GameProperties[8].PropertyName = "Shu";
        GameProperties[8].Position = 8;
        GameProperties[8].PropertyType = 0;
        GameProperties[8].PropertyPrice = 180000;
        GameProperties[8].SellValue = 90000;
        GameProperties[8].RentValue = 100000;
        GameProperties[8].colorGroup = SKY;
        GameProperties[9].PropertyName = "Embi";
        GameProperties[9].Position = 9;
        GameProperties[9].PropertyType = 0;
        GameProperties[9].PropertyPrice = 200000;
        GameProperties[9].SellValue = 100000;
        GameProperties[9].RentValue = 120000;
        GameProperties[9].colorGroup = SKY;
        GameProperties[10].PropertyName = "Free Parking";
        GameProperties[10].Position = 10;
        GameProperties[10].PropertyType = 6;
        GameProperties[11].PropertyName = "Rudny";
        GameProperties[11].Position = 11;
        GameProperties[11].PropertyType = 0;
        GameProperties[11].PropertyPrice = 230000;
        GameProperties[11].SellValue = 115000;
        GameProperties[11].RentValue = 150000;
        GameProperties[11].colorGroup = PINK;
        GameProperties[12].PropertyName = "Free Parking";
        GameProperties[12].Position = 12;
        GameProperties[12].PropertyType = 6;
        GameProperties[13].PropertyName = "Kaskelen";
        GameProperties[13].Position = 13;
        GameProperties[13].PropertyType = 0;
        GameProperties[13].PropertyPrice = 250000;
        GameProperties[13].SellValue = 125000;
        GameProperties[13].RentValue = 150000;
        GameProperties[13].colorGroup = PINK;
        GameProperties[14].PropertyName = "Aksu";
        GameProperties[14].Position = 14;
        GameProperties[14].PropertyType = 0;
        GameProperties[14].PropertyPrice = 280000;
        GameProperties[14].SellValue = 140000;
        GameProperties[14].RentValue = 180000;
        GameProperties[14].colorGroup = PINK;
        GameProperties[15].PropertyName = "Almaty-2 RailRoad";
        GameProperties[15].Position = 15;
        GameProperties[15].PropertyType = 1;
        GameProperties[15].PropertyPrice = 250000;
        GameProperties[15].SellValue = 125000;
        GameProperties[16].PropertyName = "Baikonur";
        GameProperties[16].Position = 16;
        GameProperties[16].PropertyType = 0;
        GameProperties[16].PropertyPrice = 300000;
        GameProperties[16].SellValue = 150000;
        GameProperties[16].RentValue = 200000;
        GameProperties[16].colorGroup = ORANGE;
        GameProperties[17].PropertyName = "Community Chest";
        GameProperties[17].Position = 17;
        GameProperties[17].PropertyType = 3;
        GameProperties[18].PropertyName = "Zaysan";
        GameProperties[18].Position = 18;
        GameProperties[18].PropertyType = 0;
        GameProperties[18].PropertyPrice = 320000;
        GameProperties[18].SellValue = 160000;
        GameProperties[18].RentValue = 220000;
        GameProperties[18].colorGroup = ORANGE;
        GameProperties[19].PropertyName = "Zhanaozen";
        GameProperties[19].Position = 19;
        GameProperties[19].PropertyType = 0;
        GameProperties[19].PropertyPrice = 350000;
        GameProperties[19].SellValue = 175000;
        GameProperties[19].RentValue = 250000;
        GameProperties[19].colorGroup = ORANGE;
        GameProperties[20].PropertyName = "Free Parking";
        GameProperties[20].Position = 20;
        GameProperties[20].PropertyType = 6;
        GameProperties[21].PropertyName = "Ekibastuz";
        GameProperties[21].Position = 21;
        GameProperties[21].PropertyType = 0;
        GameProperties[21].PropertyPrice = 380000;
        GameProperties[21].SellValue = 190000;
        GameProperties[21].RentValue = 280000;
        GameProperties[21].colorGroup = RED;
        GameProperties[22].PropertyName = "Chance";
        GameProperties[22].Position = 22;
        GameProperties[22].PropertyType = 2;
        GameProperties[23].PropertyName = "Qonaev";
        GameProperties[23].Position = 23;
        GameProperties[23].PropertyType = 0;
        GameProperties[23].PropertyPrice = 400000;
        GameProperties[23].SellValue = 200000;
        GameProperties[23].RentValue = 300000;
        GameProperties[23].colorGroup = RED;
        GameProperties[24].PropertyName = "Jesqazgan";
        GameProperties[24].Position = 24;
        GameProperties[24].PropertyType = 0;
        GameProperties[24].PropertyPrice = 420000;
        GameProperties[24].SellValue = 210000;
        GameProperties[24].RentValue = 300000;
        GameProperties[24].colorGroup = RED;
        GameProperties[25].PropertyName = "Nurly Jol RailRoad";
        GameProperties[25].Position = 25;
        GameProperties[25].PropertyType = 1;
        GameProperties[25].PropertyPrice = 250000;
        GameProperties[25].SellValue = 125000;
        GameProperties[26].PropertyName = "Kokshetau";
        GameProperties[26].Position = 26;
        GameProperties[26].PropertyType = 0;
        GameProperties[26].PropertyPrice = 400000;
        GameProperties[26].SellValue = 200000;
        GameProperties[26].RentValue = 330000;
        GameProperties[26].colorGroup = YELLOW;
        GameProperties[27].PropertyName = "Uralsk";
        GameProperties[27].Position = 27;
        GameProperties[27].PropertyType = 0;
        GameProperties[27].PropertyPrice = 400000;
        GameProperties[27].SellValue = 200000;
        GameProperties[27].RentValue = 350000;
        GameProperties[27].colorGroup = YELLOW;
        GameProperties[28].PropertyName = "Free Parking";
        GameProperties[28].Position = 28;
        GameProperties[28].PropertyType = 2;
        GameProperties[28].PropertyPrice = 150000;
        GameProperties[28].SellValue = 75000;
        GameProperties[29].PropertyName = "Petropavl";
        GameProperties[29].Position = 29;
        GameProperties[29].PropertyType = 0;
        GameProperties[29].PropertyPrice = 400000;
        GameProperties[29].SellValue = 200000;
        GameProperties[29].RentValue = 350000;
        GameProperties[29].colorGroup = YELLOW;
        GameProperties[30].PropertyName = "Free Parking";
        GameProperties[30].Position = 30;
        GameProperties[30].PropertyType = 6;
        GameProperties[31].PropertyName = "Kostanay";
        GameProperties[31].Position = 31;
        GameProperties[31].PropertyType = 0;
        GameProperties[31].PropertyPrice = 450000;
        GameProperties[31].SellValue = 225000;
        GameProperties[31].RentValue = 400000;
        GameProperties[31].colorGroup = GREEN;
        GameProperties[32].PropertyName = "Pavlodar";
        GameProperties[32].Position = 32;
        GameProperties[32].PropertyType = 0;
        GameProperties[32].PropertyPrice = 450000;
        GameProperties[32].SellValue = 225000;
        GameProperties[32].RentValue = 400000;
        GameProperties[32].colorGroup = GREEN;
        GameProperties[33].PropertyName = "Community Chest";
        GameProperties[33].Position = 33;
        GameProperties[33].PropertyType = 3;
        GameProperties[34].PropertyName = "Shymkent";
        GameProperties[34].Position = 34;
        GameProperties[34].PropertyType = 0;
        GameProperties[34].PropertyPrice = 450000;
        GameProperties[34].SellValue = 225000;
        GameProperties[34].RentValue = 400000;
        GameProperties[34].colorGroup = GREEN;
        GameProperties[35].PropertyName = "Nur-Sul-1 RailRoad";
        GameProperties[35].Position = 35;
        GameProperties[35].PropertyType = 1;
        GameProperties[35].PropertyPrice = 250000;
        GameProperties[35].SellValue = 125000;
        GameProperties[36].PropertyName = "Chance";
        GameProperties[36].Position = 36;
        GameProperties[36].PropertyType = 2;
        GameProperties[37].PropertyName = "Astana";
        GameProperties[37].Position = 37;
        GameProperties[37].PropertyType = 0;
        GameProperties[37].PropertyPrice = 500000;
        GameProperties[37].SellValue = 250000;
        GameProperties[37].RentValue = 450000;
        GameProperties[37].colorGroup = BLUE;
        GameProperties[38].PropertyName = "Luxury Tax";
        GameProperties[38].Position = 38;
        GameProperties[38].PropertyType = 7;
        GameProperties[39].PropertyName = "Almaty";
        GameProperties[39].Position = 39;
        GameProperties[39].PropertyType = 0;
        GameProperties[39].PropertyPrice = 500000;
        GameProperties[39].SellValue = 250000;
        GameProperties[39].RentValue = 500000;
        GameProperties[39].colorGroup = BLUE;

        NumProperties = 40;
    }

    void drawBoard()
    {
        cout << "|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|" << endl;
        cout << "|  Free   |Ekibastuz| Chance  | Qonaev  |Jesqazgan|Nurly Jol|Kokshetau| Uralsk  |  Free   |Petropavl|  Free   |" << endl;
        cout << "| Parking |         |    ?    |         |         |Railroad |         |         | Parking |         | Parking |" << endl;
        cout << "|         |         |         |         |         |         |         |         |         |         |         |" << endl;
        cout << "|         |   RED   |         |   RED   |   RED   |         |  YELLOW |  YELLOW |         | YELLOW  |         |" << endl;
        cout << "|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|" << endl;
        cout << "|         |                                                                                         |         |" << endl;
        cout << "|Zhanaozen|                                                                                         | Kostanay|" << endl;
        cout << "|         |                                                                                         |         |" << endl;
        cout << "|  ORANGE |                                                                                         |  GREEN  |" << endl;
        cout << "|---------|                                                                                         |---------|" << endl;
        cout << "|         |                                                                                         |         |" << endl;
        cout << "|  Zaysan |                                                                                         |Pavlodar |" << endl;
        cout << "|         |                                                                                         |         |" << endl;
        cout << "|  ORANGE |                                                                                         |  GREEN  |" << endl;
        cout << "|---------|                                                                                         |---------|" << endl;
        cout << "|Community|                                                                                         |Community|" << endl;
        cout << "|  Chest  |                                                                                         |  Chest  |" << endl;
        cout << "|         |                                                                                         |         |" << endl;
        cout << "|         |                                                                                         |         |" << endl;
        cout << "|---------|                                                                                         |---------|" << endl;
        cout << "|         |                                          Monopoly                                       |Shymkent |" << endl;
        cout << "| Baikonur|                                                                                         |         |" << endl;
        cout << "|         |                                                                                         |         |" << endl;
        cout << "| ORANGE  |                                                                                         |  GREEN  |" << endl;
        cout << "|---------|                                                                                         |---------|" << endl;
        cout << "|         |                                                                                         |Nur-Sul-1|" << endl;
        cout << "| Almaty-2|                                                                                         | Railroad|" << endl;
        cout << "|Railroad |                                                                                         |         |" << endl;
        cout << "|         |                                                                                         |         |" << endl;
        cout << "|---------|                                                                                         |---------|" << endl;
        cout << "|         |                                                                                         |  Chance |" << endl;
        cout << "|   Aksu  |                                                                                         |    ?    |" << endl;
        cout << "|         |                                                                                         |         |" << endl;
        cout << "|   PINK  |                                                                                         |         |" << endl;
        cout << "|---------|                                                                                         |---------|" << endl;
        cout << "|         |                                                                                         |  Astana |" << endl;
        cout << "| Kaskelen|                                                                                         |         |" << endl;
        cout << "|         |                                                                                         |         |" << endl;
        cout << "|   PINK  |                                                                                         |   BLUE  |" << endl;
        cout << "|---------|                                                                                         |---------|" << endl;
        cout << "|  Free   |                                                                                         |  Luxury |" << endl;
        cout << "| Parking |                                                                                         |   Tax   |" << endl;
        cout << "|         |                                                                                         |         |" << endl;
        cout << "|         |                                                                                         |         |" << endl;
        cout << "|---------|                                                                                         |---------|" << endl;
        cout << "|         |                                                                                         | Almaty  |" << endl;
        cout << "| Rudny   |                                                                                         |         |" << endl;
        cout << "|         |                                                                                         |         |" << endl;
        cout << "|   PINK  |                                                                                         |   BLUE  |" << endl;
        cout << "|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|" << endl;
        cout << "|  Free   |   Embi  |  Shu    |  Chance |   Esik  | Almaty-1| Income  |Khromtau |Community| Lenger  |  Start  |" << endl;
        cout << "| Parking |         |         |    ?    |         | Railroad|  Tax    |         |  Chest  |         |         |" << endl;
        cout << "|         |         |         |         |         |         |         |         |         |         | Collect |" << endl;
        cout << "|         |   SKY   |   SKY   |         |   SKY   |         |         |  BROWN  |         |  BROWN  |  500k   |" << endl;
        cout << "|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|---------|\n"
             << endl;
    }

    Property getPropInfo(int intPosition)
    {
        return GameProperties[intPosition];
    }

    Property *getPropAdd(int intPosition)
    {
        return (&GameProperties[intPosition]);
    }

    int getNumProperties()
    {
        return NumProperties;
    }

    void setOwnedProp(int intPosition, bool newOwnedProperty)
    {
        GameProperties[intPosition].IsOwned = newOwnedProperty;
    }

    void setOwner(int intPosition, Player *newOwner)
    {
        GameProperties[intPosition].PropertyOwner = newOwner;
    }

    void setOwnAllColor(int intPosition, bool newOwnAllColor)
    {
        GameProperties[intPosition].ownAllColor = newOwnAllColor;
    }

    void displayOwnedPropByPlayer(Player *inputPlayer)
    {
        int counter = 0;
        cout<<inputPlayer->PlayerName<<" owns these properties:"<<endl;
        for(int i=0; i<40; i++)
        {
            if(GameProperties[i].PropertyOwner == inputPlayer)
            {
                counter++;
                cout<<GameProperties[i].PropertyName<<" with position "<<GameProperties[i].Position<<endl;
            }
        }
        if(counter == 0)
        {
            cout<<inputPlayer->PlayerName<<" does not own any property"<<endl;
        }
        cout << endl;

        return;
    }
    void avoidBankruptcy(Player *inputPlayer)
    {
        char ans;
        cout << "\nWhat would you like to do?" << endl;
        cout << "     a) Sell Properties to Bank" << endl;
        cout << "     b) Declare Bankruptcy" << endl;
        cin >> ans;
        cin.ignore();
        while (ans != 'a' && ans != 'b' && ans != 'A' && ans != 'B')
        {
            cout << "\nPlease choose a or b: ";
            cin >> ans;
        }
        /* If the player decides to sell a house */
        if (ans == 'a' || ans == 'A')
        {

            sellProperty(inputPlayer);
            return;
        }
        /* If the player declares bankruptcy */
        if (ans == 'b' || ans == 'b')
        {
            clearscreen();
            drawBoard();
            cout << inputPlayer->PlayerName << " declared bankruptcy." << endl;
            inputPlayer->Bankrupt = true;
            return;
        }
    }
    void sellProperty(Player *inputplayer)
    {
        int pos;
        cout << "Which property would you like to sell to bank?" << endl;
        displayOwnedPropByPlayer(inputplayer);
        bool flag = true;
        while (flag)
        {
            cout << "Please write the position of the property you want to sell." << endl;
            cin >> pos;
            for (int i = 0; i < 40; i++)
            {
                if (GameProperties[i].PropertyOwner == inputplayer)
                {
                    flag = false;
                }
            }
        }
        GameProperties[pos].IsOwned = false;
        inputplayer->Wealth += GameProperties[pos].SellValue;
        GameProperties[pos].PropertyOwner = NULL;
        inputplayer->OwnedProps.pop_back();
    }
    int RailRoadNums(Player *inputplayer)
    {
        int counter = 0;
        if (GameProperties[5].PropertyOwner == inputplayer)
            counter++;
        if (GameProperties[15].PropertyOwner == inputplayer)
            counter++;
        if (GameProperties[25].PropertyOwner == inputplayer)
            counter++;
        if (GameProperties[35].PropertyOwner == inputplayer)
            counter++;
        return counter;
    }
    void chanceLand(Player *inputPlayer)
    {
        int whichChanceCard = -1;
        srand(time(0));
        whichChanceCard = ((rand() % 5) + 1);
        switch (whichChanceCard)
        {
        case 1:
            cout << inputPlayer->PlayerName << " won in a lottery. He got 200k tenge!" << endl;
            inputPlayer->Wealth += 200000;
            inputPlayer->displayStats();
            return;
        case 2:
            cout << inputPlayer->PlayerName << " has to repair car. He has to pay 200k tenge!" << endl;
            while (200000 > inputPlayer->Wealth)
            {
                cout << "\nYou cannot afford repair!" << endl;
                avoidBankruptcy(inputPlayer);
                if (inputPlayer->Bankrupt)
                    return;
            }
            inputPlayer->Wealth -= 200000;
            inputPlayer->displayStats();
            return;
        case 3:
            cout << inputPlayer->PlayerName << " won a grant from NFactorial and Chevron Fellows! Kravachik!!! He got 500k tenge" << endl;
            inputPlayer->Wealth += 500000;
            inputPlayer->displayStats();
            return;
        case 4:
            cout << inputPlayer->PlayerName << " has to pay for his tuition. He has to pay 250k tenge!" << endl;
            while (250000 > inputPlayer->Wealth)
            {
                cout << "\nYou cannot afford rent!" << endl;
                avoidBankruptcy(inputPlayer);
                if (inputPlayer->Bankrupt)
                    return;
            }
            inputPlayer->Wealth -= 250000;
            inputPlayer->displayStats();
            return;
        case 5:
            cout << "Just a safe chance. Nothing happens. Good luck!" << endl;
            inputPlayer->displayStats();
            return;
        }
    }
    void ChestLand(Player *inputPlayer)
    {
        int whichChestCard = -1;
        srand(time(0));
        whichChestCard = ((rand() % 5) + 1);
        switch (whichChestCard)
        {
        case 1:
            cout << inputPlayer->PlayerName << " won in a lottery. He got 200k tenge!" << endl;
            inputPlayer->Wealth += 200000;
            inputPlayer->displayStats();
            return;
        case 2:
            cout << inputPlayer->PlayerName << " has to repair car. He has to pay 200k tenge!" << endl;
            while (200000 > inputPlayer->Wealth)
            {
                cout << "\nYou cannot afford repair!" << endl;
                avoidBankruptcy(inputPlayer);
                if (inputPlayer->Bankrupt)
                    return;
            }
            inputPlayer->Wealth -= 200000;
            inputPlayer->displayStats();
            return;
        case 3:
            cout << inputPlayer->PlayerName << " won a grant from NFactorial and Chevron Fellows! Kravachik!!! He got 500k tenge" << endl;
            inputPlayer->Wealth += 500000;
            inputPlayer->displayStats();
            return;
        case 4:
            cout << inputPlayer->PlayerName << " has to pay for his tuition. He has to pay 250k tenge!" << endl;
            while (250000 > inputPlayer->Wealth)
            {
                cout << "\nYou cannot afford rent!" << endl;
                avoidBankruptcy(inputPlayer);
                if (inputPlayer->Bankrupt)
                    return;
            }
            inputPlayer->Wealth -= 250000;
            inputPlayer->displayStats();
            return;
        case 5:
            cout << "Just a safe chest. Nothing happens. Good luck!" << endl;
            inputPlayer->displayStats();
            return;
        }
    }
    void CalculateOwnedProps(Player *inputPlayer)
    {
        int BrownProps = 0;
        int SkyProps = 0;
        int PinkProps = 0;
        int OrangeProps = 0;
        int RedProps = 0;
        int YellowProps = 0;
        int GreenProps = 0;
        int BlueProps = 0;
        for (int i = 0; i < 40; i++)
        {
            if (GameProperties[i].PropertyOwner == inputPlayer && GameProperties[i].colorGroup == BROWN)
                BrownProps++;
            else if (GameProperties[i].PropertyOwner == inputPlayer && GameProperties[i].colorGroup == SKY)
                SkyProps++;
            else if (GameProperties[i].PropertyOwner == inputPlayer && GameProperties[i].colorGroup == PINK)
                PinkProps++;
            else if (GameProperties[i].PropertyOwner == inputPlayer && GameProperties[i].colorGroup == ORANGE)
                OrangeProps++;
            else if (GameProperties[i].PropertyOwner == inputPlayer && GameProperties[i].colorGroup == RED)
                RedProps++;
            else if (GameProperties[i].PropertyOwner == inputPlayer && GameProperties[i].colorGroup == YELLOW)
                YellowProps++;
            else if (GameProperties[i].PropertyOwner == inputPlayer && GameProperties[i].colorGroup == GREEN)
                GreenProps++;
            else if (GameProperties[i].PropertyOwner == inputPlayer && GameProperties[i].colorGroup == BLUE)
                BlueProps++;
        }
        if (BrownProps == 2)
        {
            GameProperties[1].ownAllColor = true;
            GameProperties[3].ownAllColor = true;
        }
        if (SkyProps == 3)
        {
            GameProperties[6].ownAllColor = true;
            GameProperties[8].ownAllColor = true;
            GameProperties[9].ownAllColor = true;
        }
        if (PinkProps == 3)
        {
            GameProperties[11].ownAllColor = true;
            GameProperties[13].ownAllColor = true;
            GameProperties[14].ownAllColor = true;
        }
        if (OrangeProps == 3)
        {
            GameProperties[16].ownAllColor = true;
            GameProperties[18].ownAllColor = true;
            GameProperties[19].ownAllColor = true;
        }
        if (RedProps == 3)
        {
            GameProperties[21].ownAllColor = true;
            GameProperties[23].ownAllColor = true;
            GameProperties[24].ownAllColor = true;
        }
        if (YellowProps == 3)
        {
            GameProperties[26].ownAllColor = true;
            GameProperties[27].ownAllColor = true;
            GameProperties[29].ownAllColor = true;
        }
        if (GreenProps == 3)
        {
            GameProperties[31].ownAllColor = true;
            GameProperties[32].ownAllColor = true;
            GameProperties[34].ownAllColor = true;
        }
        if (BlueProps == 2)
        {
            GameProperties[37].ownAllColor = true;
            GameProperties[39].ownAllColor = true;
        }
    }
};

int turn(GameBoard *inputBoard, Player *inputPlayer)
{
    int diceRoll = -1;
    cout<<"/////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
    cout << "It is " << inputPlayer->PlayerName << "'s turn!" << endl;
    inputPlayer->displayStats();
    cout << "What would you like to do?:" << "\n     a) Start Turn \n     b) Display All Properties You Own \n     c) Show Monopoly Board" <<endl;
    char cont = 'z';
    while(cont != 'a' && cont != 'b' && cont != 'c' && cont != 'A'&& cont != 'B' && cont != 'C') {
        cout << "\n\n Please enter a, b, or c: ";
        cin >> cont;
    }
    cout<<endl;
    if(cont == 'b' || cont =='B')
    {
        inputBoard->displayOwnedPropByPlayer(inputPlayer);
        cout<<"Enter any character to roll the dice"<<endl;
        cin>>cont;
    }
    if(cont == 'c' || cont == 'C')
    {
        inputBoard->drawBoard();
        cout<<"Enter any character to roll the dice"<<endl;
        cin>>cont;
    }
    
    diceRoll = rollDie();
    cout<<endl;
    cout << inputPlayer->PlayerName<<" rolled: " << diceRoll << "!" << endl;
    int boardpos = diceRoll + inputPlayer->PlayerPosition;
    if (boardpos > 39) // If the player will pass go in the turn, they will collect 500k
    {
        boardpos = boardpos % 40;
        inputPlayer->PlayerPosition = boardpos;
        inputPlayer->Wealth += 500000;
        cout << "\nYou passed Start, collect 500k tenge!" << endl;
    }
    else
    {
        inputPlayer->PlayerPosition += diceRoll;
    }
    cout << "Now you are standing on " << inputBoard->getPropInfo(boardpos).PropertyName <<" "<<inputBoard->getPropInfo(boardpos).Position<<endl;
    switch (inputBoard->getPropInfo(boardpos).PropertyType)
    {
    /* If the property is a standard property */
    case 0:
        if (inputBoard->getPropInfo(inputPlayer->PlayerPosition).IsOwned)
        {
            if (inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyOwner == inputPlayer)
            {
                inputBoard->drawBoard();
                cout << "You own this place" << endl;
                return -1;
            }
            else // If another player owns the propeyourty, the player will be charged the proper rent
            {
                cout << inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyName << " is owned by" << inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyOwner->PlayerName << endl;
                cout << "The Rent is ";
                if (inputBoard->getPropInfo(inputPlayer->PlayerPosition).ownAllColor) // If all colors are owned by one person
                {
                    cout << 3 * inputBoard->getPropInfo(inputPlayer->PlayerPosition).RentValue << " Because "<<inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyOwner->PlayerName<<" has all properties of this color!"<<endl;
                    while (3 * inputBoard->getPropInfo(inputPlayer->PlayerPosition).RentValue > inputPlayer->Wealth)
                    {
                        cout << "\nYou cannot afford rent!" << endl;
                        inputBoard->avoidBankruptcy(inputPlayer);
                        if (inputPlayer->Bankrupt)
                            return -1;
                    }
                    inputPlayer->Wealth -= 3 * inputBoard->getPropInfo(inputPlayer->PlayerPosition).RentValue;
                    inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyOwner->Wealth += 3 * inputBoard->getPropInfo(inputPlayer->PlayerPosition).RentValue;
                    cout << "\n"
                         << inputPlayer->PlayerName << " paid rent! On Molodec!" << endl;
                    return -1;
                }
                else // If not all houses of one color are owned by 1 person
                {
                    cout << inputBoard->getPropInfo(inputPlayer->PlayerPosition).RentValue << endl;
                    while (inputBoard->getPropInfo(inputPlayer->PlayerPosition).RentValue > inputPlayer->Wealth)
                    {
                        cout << "\nYou cannot afford rent!" << endl;
                        inputBoard->avoidBankruptcy(inputPlayer);
                        if (inputPlayer->Bankrupt)
                            return -1;
                    }
                    inputPlayer->Wealth -= inputBoard->getPropInfo(inputPlayer->PlayerPosition).RentValue;
                    inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyOwner->Wealth += inputBoard->getPropInfo(inputPlayer->PlayerPosition).RentValue;
                    cout << "\n"
                         << inputPlayer->PlayerName << " paid rent! On Molodec!" << endl;
                    return -1;
                }
            }
        }
        else // If the property is not owned
        {
            char ans;
            cout << "\nThis property is available. Would you like to buy?" << endl;
            cout << "a) Yes" << endl;
            cout << "b) No" << endl;
            cin >> ans;
            while (ans != 'a' && ans != 'b' && ans != 'A' && ans != 'B')
            {
                cout << "\nPlease choose a or b: ";
                cin >> ans;
            }
            if (ans == 'a' || ans == 'A')
            {
                if (inputPlayer->Wealth < inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyPrice)
                { // If the player can't afford to buy the property
                    cout << "\nYou can't afford to buy this property :(" << endl;
                    return -1;
                }
                else
                { // If the player can afford to buy the property, they will be able to
                    inputBoard->drawBoard();
                    cout << "\n"
                         << inputPlayer->PlayerName << " successfully bought " << inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyName << "!" << endl;
                    inputPlayer->Wealth -= inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyPrice;
                    inputBoard->setOwnedProp(inputPlayer->PlayerPosition, true);
                    inputBoard->setOwner(inputPlayer->PlayerPosition, inputPlayer);
                    inputPlayer->OwnedProps.push_back(inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyName);
                    inputBoard->CalculateOwnedProps(inputPlayer);
                    if(inputBoard->getPropInfo(inputPlayer->PlayerPosition).ownAllColor == true)
                    {
                        cout<<"Congratulations! You have all properties of this color!"<<endl;
                    }
                }
            }
        }
    // If property is railroad
    case 1:
        if (inputBoard->getPropInfo(inputPlayer->PlayerPosition).IsOwned) // If the property is owned
        {
            if (inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyOwner == inputPlayer) // If player owns this property
            {
                return -1;
            }
            else // If another player owns the property, the player will be charged the proper rent
            {
                cout << inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyName << " is owned by" << inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyOwner->PlayerName << endl;
                cout << "The Rent is ";
                switch (inputBoard->RailRoadNums(inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyOwner))
                {
                case 1: // If the owner owns one railroad
                    cout << 150000 << endl;
                    while (150000 > inputPlayer->Wealth)
                    {
                        cout << "\nYou cannot afford rent!" << endl;
                        inputBoard->avoidBankruptcy(inputPlayer);
                        if (inputPlayer->Bankrupt)
                            return -1;
                    }
                    inputPlayer->Wealth -= 150000;
                    inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyOwner->Wealth += 150000;
                    
                    inputBoard->drawBoard();
                    cout << "\n"
                         << inputPlayer->PlayerName << " paid rent! On Molodec!" << endl;
                    return -1;
                case 2: // If the owner owns two railroad
                    cout << 300000 << endl;
                    while (300000 > inputPlayer->Wealth)
                    {
                        cout << "\nYou cannot afford rent!" << endl;
                        inputBoard->avoidBankruptcy(inputPlayer);
                        if (inputPlayer->Bankrupt)
                            return -1;
                    }
                    inputPlayer->Wealth -= 300000;
                    inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyOwner->Wealth += 300000;
                    
                    inputBoard->drawBoard();
                    cout << "\n"
                         << inputPlayer->PlayerName << " paid rent! On Molodec!" << endl;
                    return -1;
                case 3: // If the owner owns three railroad
                    cout << 450000 << endl;
                    while (450000 > inputPlayer->Wealth)
                    {
                        cout << "\nYou cannot afford rent!" << endl;
                        inputBoard->avoidBankruptcy(inputPlayer);
                        if (inputPlayer->Bankrupt)
                            return -1;
                    }
                    inputPlayer->Wealth -= 450000;
                    inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyOwner->Wealth += 450000;
                    
                    inputBoard->drawBoard();
                    cout << "\n"
                         << inputPlayer->PlayerName << " paid rent! On Molodec!" << endl;
                    return -1;
                case 4: // If the owner owns four railroad
                    cout << 600000 << endl;
                    while (600000 > inputPlayer->Wealth)
                    {
                        cout << "\nYou cannot afford rent!" << endl;
                        inputBoard->avoidBankruptcy(inputPlayer);
                        if (inputPlayer->Bankrupt)
                            return -1;
                    }
                    inputPlayer->Wealth -= 600000;
                    inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyOwner->Wealth += 600000;
                    
                    inputBoard->drawBoard();
                    cout << "\n"
                         << inputPlayer->PlayerName << " paid rent! On Molodec!" << endl;
                    return -1;
                }
            }
        }
        else // If the property is not owned
        {
            char ans;
            cout << "\nThis property is available. Would you like to buy?" << endl;
            cout << "a) Yes" << endl;
            cout << "b) No" << endl;
            cin >> ans;
            while (ans != 'a' && ans != 'b' && ans != 'A' && ans != 'B')
            {
                cout << "\nPlease choose a or b: ";
                cin >> ans;
            }
            if (ans == 'a' || ans == 'A')
            {
                if (inputPlayer->Wealth < inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyPrice)
                { // If the player can't afford to buy the property
                    cout << "\nYou can't afford to buy this property!" << endl;
                    return -1;
                }
                else
                { // If the player can afford to buy the property, they will be able to
                    
                    inputBoard->drawBoard();
                    cout << "\n"
                         << inputPlayer->PlayerName << " successfully bought " << inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyName << "!" << endl;
                    inputPlayer->Wealth -= inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyPrice;
                    inputBoard->setOwnedProp(inputPlayer->PlayerPosition, true);
                    inputBoard->setOwner(inputPlayer->PlayerPosition, inputPlayer);
                    inputPlayer->OwnedProps.push_back(inputBoard->getPropInfo(inputPlayer->PlayerPosition).PropertyName);
                    inputBoard->CalculateOwnedProps(inputPlayer);
                    inputBoard->drawBoard();
                    return -1;
                }
            }
            else {
                return -1;
            }
        }
    case 2:
        
        cout << inputPlayer->PlayerName << " landed on Chance!" << endl;
        inputBoard->chanceLand(inputPlayer);
        return -1;
    case 3:
        
        cout << inputPlayer->PlayerName << " landed on Coomunity Chest!" << endl;
        inputBoard->ChestLand(inputPlayer);
        return -1;
    case 4:
        
        cout << inputPlayer->PlayerName << " landed on Start! The Player gets 500k tenge!" << endl;
        inputPlayer->Wealth += 500000;
        inputBoard->drawBoard();
        return -1;
    case 5:
        cout << inputPlayer->PlayerName << " landed on Income Tax. The player has to pay 400k tenge" << endl;
        while (400000 > inputPlayer->Wealth)
        {
            cout << "\nYou cannot afford income tax!" << endl;
            inputBoard->avoidBankruptcy(inputPlayer);
            if (inputPlayer->Bankrupt)
                return -1;
        }
        cout<<inputPlayer->PlayerName<<" paid the Income Tax. Molodec"<<endl;
        inputPlayer->Wealth -= 400000;
        inputPlayer->displayStats();
        return -1;
    case 6:
    {
        cout << inputPlayer->PlayerName << " landed on Free Parking" << endl;
        return -1;
    }
    case 7:
        cout << inputPlayer->PlayerName << " landed on Luxury Tax. The player has to pay 400k tenge" << endl;
        while (400000 > inputPlayer->Wealth)
        {
            cout << "\nYou cannot afford luxury tax!" << endl;
            inputBoard->avoidBankruptcy(inputPlayer);
            if (inputPlayer->Bankrupt)
                return -1;
        }
        cout<<inputPlayer->PlayerName<<" paid the Luxury Tax. Molodec"<<endl;
        inputPlayer->Wealth -= 400000;
        inputPlayer->displayStats();
        return -1;
    }
}

vector<vector<Property *>> ownedProperties;
Player gamePlayers[8]; // Array of players, sized to the max number of players (8)

int main()
{
    GameBoard *Monopoly = new GameBoard();
    cout << "\n How many players? ";
    cin >> numPlayers;
    while ((numPlayers < 2) || (numPlayers > 8))
    {
        if (numPlayers < 2)
        {
            cout << "\nThere must be at least 2 players. Please input how many players there are: ";
            cin >> numPlayers;
        }
        if (numPlayers > 8)
        {
            cout << "\nThere can only be 8 players at once. Please input how many players there are: ";
            cin >> numPlayers;
        }
    }
    cin.ignore();
    for (int i = 0; i < numPlayers; i++)
    {
        cout << "\nWhat is Player " << (i + 1) << "'s name? ";
        getline(cin, gamePlayers[i].PlayerName); // Collects player's name

        vector<Property *> playerProperties;         // Creates a vector of property pointers to put into the ownedProperties 2D vector
        ownedProperties.push_back(playerProperties); // Creates a new row in the 2D vector ownedProperties for each player2
        gamePlayers[i].PlayerNum = i;
    }
    clearscreen();
    cout << "Welcome to Monopoly!\n"
         << endl;
    Monopoly->drawBoard();

    bool continuePlaying = true;
    while (continuePlaying)
    {

        turn(Monopoly, &gamePlayers[turnNum]);

        int numRemainPlayers = numPlayers;
        Player *winningPlayer;

        /* This loop checks to see if all but one player is bankrupt, and if so, declares that one player the winner */
        for (int i = 0; i < numPlayers; i++)
        {
            if (gamePlayers[i].Bankrupt)
            {
                numRemainPlayers--;
            }
            else
            {
                winningPlayer = &gamePlayers[i];
            }
        }
        /* If there is a winner */
        if (numRemainPlayers == 1)
        {
            cout << "\nWe have a winner! Congratulations " << winningPlayer->PlayerName << "!" << endl;
            continuePlaying = false;
        }
        if (turnNum + 1 == numPlayers)
        {
            turnNum = 0;
        }
        else
        {
            turnNum++;
        }
        while (gamePlayers[turnNum].Bankrupt)
        {
            if (turnNum + 1 == numPlayers)
            {
                turnNum = 0;
            }
            else
            {
                turnNum++;
            }
        }
    }
    return 0;
}