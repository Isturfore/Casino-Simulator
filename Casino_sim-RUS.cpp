#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <Windows.h>

using namespace std;

void LuckyRouletteRules()//правила игры удачная рулетка
{
    cout << "\n\n\t\t\t::Правила игры \"Удачная рулетка\"::" << endl << endl;
    cout << "\t\tИгрок делает ставку и выбирает на что он ставит.\n\t\tИгрок может поставить на:" << endl;

    cout << "\n\t\t\tНечетные числа (вероятность выигрыша составляет 18 к 37 | ставка умножается в 1.3 раза)";
    cout << "\n\t\t\tЧетные числа (вероятность выигрыша составляет 19 к 37, возможен джекпот - число 0 | ставка умножается в 1.3 раза, а джекпот - в 2 раза)";
    cout << "\n\t\t\tЗеленое число (вероятность выигрыша 1 к 37 - число джекпота 0 | ставка умножается в 5 раз)" << endl << endl;
}
void LuckyRoulette(int &pbalance)//логика игры удачная рулетка
{
    string YN;
    int bet;
    int choice;
    int random;
    string stop;

    cout << endl << endl << endl << "\t\t\tДобро пожаловать в игру \"Удачная рулетка\", вам рассказать правила?" << endl << endl;
    while (true)
    {
        cout << "\tYes/No: ";
        cin >> YN;
        transform(YN.begin(), YN.end(), YN.begin(), ::tolower);

        if (YN != "yes" && YN != "no")
        {
            cout << "\tНеверный ввод, попробуйте еще раз!" << endl;
        }
        else if (YN == "yes")
        {
            LuckyRouletteRules();

            break;
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << "\tВаш баланс: " << pbalance << "$" << endl << endl;
        while (true)
        {
            cout << "\tПоставьте ставку: ";
            cin >> bet;
            if (bet > pbalance || bet < 1)
            {
                cout << "\n\tСтавка не может быть больше, чем ваш баланс, попробуйте еще раз!" << endl;
            }
            else
            {
                pbalance = pbalance - bet;

                break;
            }
        }

        cout << endl << endl << "\tВаш баланс: " << pbalance << "$" << endl;
        cout << "\tВаша ставка: " << bet << "$" << endl << endl << endl;

        cout << "\t\tВыберите на что ставите: " << endl << endl;

        cout << "\n\t\t\t1 - Нечетные числа (вероятность выигрыша составляет 18 к 37 | ставка умножается в 1.3 раза)";
        cout << "\n\t\t\t2 - Четные числа (вероятность выигрыша составляет 19 к 37, возможен джекпот - число 0 | ставка умножается в 1.3 раза, а джекпот - в 2 раза)";
        cout << "\n\t\t\t3 - Зеленое число (вероятность выигрыша 1 к 37 - число джекпота 0 | ставка умножается в 5 раз)" << endl << endl;

        while (true)
        {
            cout << "\t\tВвод: ";
            cin >> choice;
            if (choice != 1 && choice != 2 && choice != 3)
            {
                cout << "\t\tОшибка! Несуществующий вариант. Попробуйте еще раз!" << endl;
            }
            else
            {
                break;
            }
        }

        cout << "\t\tДанные: " << endl << endl;

        cout << endl << endl << "\tВаш баланс: " << pbalance << "$" << endl;
        cout << "\tВаша ставка: " << bet << "$" << endl;

        cout << "\tВаш вариант: " << choice << endl << endl << endl;

        if (choice == 1)
        {
            random = rand() % 37;

            for (int i = 0; i <= random; i++)
            {
                Sleep(200);
                cout << "\tЧисло: " << i << endl;
                if (i == random)
                {
                    if (random % 2 != 0)
                    {
                        bet *= 1.3;
                        pbalance += bet;
                        bet = 0;

                        cout << "\t\tПоздравляем с победой!" << endl;
                        cout << "\tВаш баланс: " << pbalance << "$" << endl << endl << endl;
                    }

                    else
                    {
                        pbalance -= bet;
                        bet = 0;
                        cout << "\t\tК сожалению вы проиграли ставку!" << endl << endl;
                        cout << "\tВаш баланс: " << pbalance << "$" << endl << endl << endl;

                        break;
                    }

                    break;
                }
            }
        }
        if (choice == 2)
        {
            random = rand() % 37;

            for (int i = 0; i <= random; i++)
            {
                Sleep(200);
                cout << "\tЧисло: " << i << endl;
                if (i == random)
                {
                    if (random % 2 == 0 && random != 0)
                    {
                        bet *= 1.3;
                        pbalance += bet;
                        bet = 0;

                        cout << "\t\tПоздравляем с победой!" << endl;
                        cout << "\tВаш баланс: " << pbalance << "$" << endl << endl << endl;
                    }
                    else if (random == 0)
                    {
                        bet *= 2;
                        pbalance += bet;
                        bet = 0;

                        cout << "\t\tПоздравляем с выигрышом джекпота!" << endl;
                        cout << "\tВаш баланс: " << pbalance << "$" << endl << endl << endl;
                    }

                    else
                    {
                        pbalance -= bet;
                        bet = 0;
                        cout << "\t\tК сожалению вы проиграли ставку!" << endl << endl;
                        cout << "\tВаш баланс: " << pbalance << "$" << endl << endl << endl;

                        break;
                    }

                    break;
                }
            }
        }
        if (choice == 3)
        {
            random = rand() % 37;

            for (int i = 0; i <= random; i++)
            {
                Sleep(200);
                cout << "\tЧисло: " << i << endl;
                if (i == random)
                {
                    if (random == 0)
                    {
                        bet *= 5;
                        pbalance += bet;
                        bet = 0;

                        cout << "\t\tПоздравляем с выигрышом джекпота!" << endl;
                        cout << "\tВаш баланс: " << pbalance << "$" << endl << endl << endl;
                    }

                    else
                    {
                        pbalance -= bet;
                        bet = 0;
                        cout << "\t\tК сожалению вы проиграли ставку!" << endl << endl;
                        cout << "\tВаш баланс: " << pbalance << "$" << endl << endl << endl;

                        break;
                    }

                    break;
                }
            }
        }
        cout << "\tХотите закончить? Yes/No: ";
        cin >> stop;
        transform(stop.begin(), stop.end(), stop.begin(), ::tolower);

        if (stop == "yes")
        {
            

            break;
        }
        else if (stop == "no")
        {
            continue;
        }
        else
        {
            cout << "\tВы произвели неверный ввод, попробуйте еще раз!" << endl;
        }
    }
}

void DiceRules()//правила игры кости
{
    cout << "\n\n\t\t\t::Правила игры \"Кости\"::" << endl << endl;
    cout << "\t\tИгрок делает ставку и выбирает количество человек, с которыми будет играть.\n\t\tЭто может быть 2, 3, 4, 5 человек." << endl;

    cout << "\n\t\t\tПри победе игроку начисляют свои и все деньги тех кто играл\n\t\t\tПри проигрыше ваши деньги соответственно идут победителю." << endl << endl;
    cout << "\n\t\tШансы выиграть при определенном количестве человек: " << endl << endl;
    cout << "\n\t\t\t2 человека - 50% или 1 к 2\n\t\t\t3 человека - 33.(3)% или 1 к 3\n\t\t\t4 человека - 25% или 1 к 4\n\t\t\t5 человек - 20% или 1 к 5" << endl << endl;
}
void Dice(int &pbalance)
{
    string YN;
    double bet;
    int choice;
    int random;
    string stop;

    cout << endl << endl << endl << "\t\t\tДобро пожаловать в игру \"Кости\", вам рассказать правила?" << endl << endl;
    while (true)
    {
        cout << "\tYes/No: ";
        cin >> YN;
        transform(YN.begin(), YN.end(), YN.begin(), ::tolower);

        if (YN != "yes" && YN != "no")
        {
            cout << "\tНеверный ввод, попробуйте еще раз!" << endl << endl;
        }
        else if (YN == "yes")
        {
            DiceRules();

            break;
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << "\tВаш баланс: " << pbalance << "$" << endl << endl;
        while (true)
        {
            cout << "\tПоставьте ставку: ";
            cin >> bet;
            if (bet > pbalance || bet < 1)
            {
                cout << "\n\tСтавка не может быть больше, чем ваш баланс, попробуйте еще раз!" << endl;
            }
            else
            {
                pbalance = pbalance - bet;

                break;
            }
        }

        cout << endl << endl << "\tВаш баланс: " << pbalance << "$" << endl;
        cout << "\tВаша ставка: " << bet << "$" << endl << endl << endl;

        cout << "\t\tВыберите количество людей: " << endl << endl;

        cout << "\n\t\t\t1: 2 человека - 50% или 1 к 2\n\t\t\t2: 3 человека - 33.(3)% или 1 к 3\n\t\t\t3: 4 человека - 25% или 1 к 4\n\t\t\t4: 5 человек - 20% или 1 к 5" << endl << endl;

        while (true)
        {
            cout << "\t\tВвод: ";
            cin >> choice;
            if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
            {
                cout << "\t\tОшибка! Несуществующий вариант. Попробуйте еще раз!" << endl;
            }
            else
            {
                break;
            }
        }

        cout << "\t\tДанные: " << endl << endl;

        cout << endl << endl << "\tВаш баланс: " << pbalance << "$" << endl;
        cout << "\tВаша ставка: " << bet << "$" << endl;

        cout << "\tВаш вариант: " << choice << endl << endl << endl;

        switch (choice)
        {
        case 1:
        {
            cout << "\t\t\t\t\tPlayer 1 (Вы)\t\t\tPlayer 2" << endl << endl;

            random = rand() % 2;

            break;
        }
        case 2:
        {
            cout << "\t\t\tPlayer 1 (Вы)\t\t\tPlayer 2\t\t\tPlayer 3" << endl << endl;

            random = rand() % 3;

            break;
        }
        case 3:
        {
            cout << "\t\t\tPlayer 1 (Вы)\t\t\tPlayer 2\t\t\tPlayer 3\n\n\n\t\t\t\t\t   Player 4" << endl << endl;

            random = rand() % 4;

            break;
        }
        case 4:
        {
            cout << "\t\t\tPlayer 1 (Вы)\t\t\tPlayer 2\t\t\tPlayer 3\n\n\n\t\t\t\t\t   Player 4\t\t\tPlayer 5" << endl << endl;

            random = rand() % 5;

            break;
        }
        //должен быть дефолт но мне не нужен
        }

        for (int i = 10; i != 0; i--)
        {
            Sleep(1000);

            cout << "\tРезультаты через " << i << " секунд!" << endl;
        }
 
        if (random != 0)
        {
            cout << endl << "\t\tВы проиграли, победил Player " << random + 1 << endl << endl;

            cout << "\tБаланс: " << pbalance << "$" << endl << endl << endl;

            bet = 0;
        }
        else
        {
            cout << endl << "Вы победили!" << endl << endl;
            switch (choice)
            {
            case 1:
            {
                bet *= 2;
                pbalance += bet;
                bet = 0;

                cout << "\tБаланс: " << pbalance << "$" << endl << endl << endl;

                break;
            }
            case 2:
            {
                bet *= 3;
                pbalance += bet;
                bet = 0;

                cout << "\tБаланс: " << pbalance << "$" << endl << endl << endl;

                break;
            }
            case 3:
            {
                bet *= 4;
                pbalance += bet;
                bet = 0;

                cout << "\tБаланс: " << pbalance << "$" << endl << endl << endl;

                break;
            }
            case 4:
            {
                bet *= 5;
                pbalance += bet;
                bet = 0;

                cout << "\tБаланс: " << pbalance << "$" << endl << endl << endl;

                break;
            }
            //Тут должен быть дефолт но мне он не нужен
            }
        }

        cout << "\tХотите закончить? Yes/No: ";
        cin >> stop;
        transform(stop.begin(), stop.end(), stop.begin(), ::tolower);

        if (stop == "yes")
        {
            break;
        }
        else if (stop == "no")
        {
            continue;
        }
        else
        {
            cout << "\tВы произвели неверный ввод, попробуйте еще раз!" << endl;
        }
    }
}

void BlackjackRules()//правила игры блэкджек
{
    cout << "\n\n\t\t\t::Правила игры \"Блэкджек\"::" << endl << endl;
    cout << "\t\tВ игре обычно участвует 4 человека и дилер, за победу ставка удваивается и складывается с вашим балансом. "<< endl;

    cout << "\n\t\t\tBLACKJACK (Черный валет) - одна из самых популярных карточных игр.";
    cout << "\n\t\t\tЗадача игроков - набрать большее число очков, чем дилер, но не больше 21.";
    cout << "\n\t\t\tПомните, что игрок, набравший больше 21 очка сразу проигрывает игру, за исключением ничьи с дилером (Если у дилера тоже больше 21 очка).";
    cout << "\n\t\t\tВначале игры каждому участнику будут выданы по 2 карты. В последствии игрок может решить, брать ему карту или нет, воспользовавшись кнопками: 'Взять' или 'Хватит' соответственно.";
    cout << "\n\t\t\tЕсли при раздаче двух карт игроку выпало 21 очко - он получил BLACKJACK, но не стоит радоваться, ведь BLACKJACK может получить и дилер, а значит Вы сыграете вничью! В зависимости от карт" << endl << endl;

}
void Blackjack(int &pbalance)//логика игры блэкджек
{
    string YN;
    double bet;
    int m1, m2, md, m4, m5;
    int random;
    int TS;
    bool m1b, m2b, mdb, m4b, m5b;
    string stop;

    m1 = m2 = md = m4 = m5 = 0;
    m1b = m2b = mdb = m4b = m5b = false;

    cout << endl << endl << endl << "\t\t\tДобро пожаловать в игру \"Блэкджек\", вам рассказать правила?" << endl << endl;
    while (true)
    {
        cout << "\tYes/No: ";
        cin >> YN;
        transform(YN.begin(), YN.end(), YN.begin(), ::tolower);

        if (YN != "yes" && YN != "no")
        {
            cout << "\tНеверный ввод, попробуйте еще раз!" << endl << endl;
        }
        else if (YN == "yes")
        {
            BlackjackRules();

            break;
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        m1 = m2 = md = m4 = m5 = 0;
        m1b = m2b = mdb = m4b = m5b = false;

        cout << "\tВаш баланс: " << pbalance << "$" << endl << endl;
        while (true)
        {
            cout << "\tПоставьте ставку: ";
            cin >> bet;
            if (bet > pbalance || bet < 1)
            {
                cout << "\n\tСтавка не может быть больше, чем ваш баланс, попробуйте еще раз!" << endl;
            }
            else
            {
                pbalance = pbalance - bet;

                break;
            }
        }

        cout << endl << endl << "\tВаш баланс: " << pbalance << "$" << endl;
        cout << "\tВаша ставка: " << bet << "$" << endl << endl << endl;

        for (int y = 0; y < 2; y++)
        {
            cout << endl << endl << endl << endl << endl;
            for (int g = 0; g < 200; g++)
            {
                cout << "_";
            }
            cout << endl << endl << endl << endl << endl;
            for (int i = 0; i < 5; i++)
            {
                random = rand() % 11;
                Sleep(500);
                switch (i)
                {
                case 0:
                {
                    m1 += random + 1;
                    cout << "\t\t\t[Player 1 (Вы)] (очков " << m1 << ")";

                    break;
                }
                case 1:
                {
                    m2 += random + 1;
                    cout << "\t\t\tPlayer 2" << " (очков " << m2 << ")";

                    break;
                }
                case 2:
                {
                    md += random + 1;
                    cout << "\t\t\t|Diler| 3 (очков " << "?" << ")";

                    break;
                }
                case 3:
                {
                    m4 += random + 1;
                    cout << "\n\n\n\t\t\t\t\t\tPlayer 4 (очков " << m4 << ")";

                    break;
                }
                case 4:
                {
                    m5 += random + 1;
                    cout << "\t\t\tPlayer 5" << " (очков " << m5 << ")";

                    break;
                }
                //должен быть дефолт но мне он тут не нужен сейчас
                }
            }
        }
        for (int n = 0; ; n++)
        {
            cout << endl << endl << endl << endl << endl;
            for (int g = 0; g < 200; g++)
            {
                cout << "_";
            }
            cout << endl << endl << endl << endl << endl;
            for (int v = 0; v < 5; v++)
            {
                random = rand() % 11;
                Sleep(500);
                switch (v)
                {
                case 0:
                {
                    while (true)
                    {
                        cout << "\t1 - Взять, 2 - Хватит: ";
                        cin >> TS;
                        cout << endl;
                        if (TS == 1)
                        {
                            m1 += random + 1;

                            break;
                        }
                        else if (TS == 2)
                        {
                            m1b = true;

                            break;
                        }
                        else
                        {
                            cout << "\tНеверный ввод, попробуйте еще раз!" << endl << endl;
                        }
                    }
                    if (m1 == 21)
                    {
                        cout << "\t\t\t[Player 1 (Вы)] (очков " << m1 << ") {BLACKJACK}";
                    }
                    else if (m1 > 21)
                    {
                        cout << "\t\t\t[Player 1 (Вы)] (очков " << m1 << ") {LOSE}";
                    }
                    else
                    {
                        cout << "\t\t\t[Player 1 (Вы)] (очков " << m1 << ")";
                    }

                    break;
                }
                case 1:
                {
                    if (m2 < 17)
                    {
                        m2 += random + 1;
                    }
                    else
                    {
                        m2b = true;
                    }
                    if (m2 == 21)
                    {
                        cout << "\t\t\tPlayer 2" << " (очков " << m2 << ") {BLACKJACK}";
                    }
                    else if (m2 > 21)
                    {
                        cout << "\t\t\tPlayer 2" << " (очков " << m2 << ") {LOSE}";
                    }
                    else
                    {
                        cout << "\t\t\tPlayer 2" << " (очков " << m2 << ")";
                    }

                    break;
                }
                case 2:
                {
                    if (md < 17)
                    {
                        md += random + 1;
                    }
                    else
                    {
                        mdb = true;
                    }
                    cout << "\t\t\t|Diler| 3 (очков " << "?" << ")";

                    break;
                }
                case 3:
                {
                    if (m4 < 17)
                    {
                        m4 += random + 1;
                    }
                    else
                    {
                        m4b = true;
                    }
                    if (m4 == 21)
                    {
                        cout << "\n\n\n\t\t\t\t\t\tPlayer 4 (очков " << m4 << ") {BLACKJACK}";
                    }
                    else if (m4 > 21)
                    {
                        cout << "\n\n\n\t\t\t\t\t\tPlayer 4 (очков " << m4 << ") {LOSE}";
                    }
                    else
                    {
                        cout << "\n\n\n\t\t\t\t\t\tPlayer 4 (очков " << m4 << ")";
                    }

                    break;
                }
                case 4:
                {
                    if (m5 < 17)
                    {
                        m5 += random + 1;
                    }
                    else
                    {
                        m5b = true;
                    }
                    if (m5 == 21)
                    {
                        cout << "\t\t\tPlayer 5" << " (очков " << m5 << ") {BLACKJACK}";
                    }
                    else if (m5 > 21)
                    {
                        cout << "\t\t\tPlayer 5" << " (очков " << m5 << ") {LOSE}";
                    }
                    else
                    {
                        cout << "\t\t\tPlayer 5" << " (очков " << m5 << ")";
                    }

                    break;
                }
                //должен быть дефолт но мне он тут не нужен сейчас
                }
            }
            if (m1b == true && m2b == true && mdb == true && m4b == true && m5b == true)
            {
                cout << endl << endl << endl << endl << endl;
                for (int h = 0; h < 200; h++)
                {
                    cout << "_";
                }
                cout << "\n\n\n\t\tФинальные результаты: " << endl << endl << endl;
                for (int v = 0; v < 5; v++)
                {
                    random = rand() % 11;
                    Sleep(500);
                    switch (v)
                    {
                    case 0:
                    {
                        if (m1 == 21)
                        {
                            cout << "\t\t\t[Player 1 (Вы)] (очков " << m1 << ") {BLACKJACK}";
                        }
                        else if (m1 > 21)
                        {
                            cout << "\t\t\t[Player 1 (Вы)] (очков " << m1 << ") {LOSE}";
                        }
                        else
                        {
                            cout << "\t\t\t[Player 1 (Вы)] (очков " << m1 << ")";
                        }

                        break;
                    }
                    case 1:
                    {
                        if (m2 == 21)
                        {
                            cout << "\t\t\tPlayer 2" << " (очков " << m2 << ") {BLACKJACK}";
                        }
                        else if (m2 > 21)
                        {
                            cout << "\t\t\tPlayer 2" << " (очков " << m2 << ") {LOSE}";
                        }
                        else
                        {
                            cout << "\t\t\tPlayer 2" << " (очков " << m2 << ")";
                        }

                        break;
                    }
                    case 2:
                    {
                        if (md == 21)
                        {
                            cout << "\t\t\t|Diler| 3 (очков " << md << ") {BLACKJACK}";
                        }
                        else if (md > 21)
                        {
                            cout << "\t\t\t|Diler| 3 (очков " << md << ") {LOSE}";
                        }
                        else
                        {
                            cout << "\t\t\t|Diler| 3 (очков " << md << ")";
                        }

                        break;
                    }
                    case 3:
                    {
                        if (m4 == 21)
                        {
                            cout << "\n\n\n\t\t\t\t\t\tPlayer 4 (очков " << m4 << ") {BLACKJACK}";
                        }
                        else if (m4 > 21)
                        {
                            cout << "\n\n\n\t\t\t\t\t\tPlayer 4 (очков " << m4 << ") {LOSE}";
                        }
                        else
                        {
                            cout << "\n\n\n\t\t\t\t\t\tPlayer 4 (очков " << m4 << ")";
                        }

                        break;
                    }
                    case 4:
                    {
                        if (m2 == 21)
                        {
                            cout << "\t\t\tPlayer 5" << " (очков " << m5 << ") {BLACKJACK}";
                        }
                        else if (m2 > 21)
                        {
                            cout << "\t\t\tPlayer 5" << " (очков " << m5 << ") {LOSE}";
                        }
                        else
                        {
                            cout << "\t\t\tPlayer 5" << " (очков " << m5 << ")";
                        }

                        break;
                    }
                    //должен быть дефолт но мне он тут не нужен сейчас
                    }
                }

                if ((m1 < md && md <= 21) || m1 > 21)
                {
                    cout << endl << endl << endl << endl << endl << "\t\tВы проиграли!" << endl << endl;
                    bet = 0;
                    cout << "Ваш баланс: " << pbalance << "$";
                }
                else if ((m1 == md) || (m1 > 21 && md > 21))
                {
                    cout << endl << endl << endl << endl << endl << "\t\tНичья!" << endl << endl;
                    pbalance += bet;
                    bet = 0;
                    cout << "Ваш баланс: " << pbalance << "$";
                }
                else
                {
                    cout << endl << endl << endl << endl << endl << "\t\tВы победили!" << endl << endl;
                    pbalance += bet * 2;
                    bet = 0;
                    cout << "Ваш баланс: " << pbalance << "$";
                }

                break;
            }
        }
        cout << "\tХотите закончить? Yes/No: ";
        cin >> stop;
        transform(stop.begin(), stop.end(), stop.begin(), ::tolower);

        if (stop == "yes")
        {
            break;
        }
        else if (stop == "no")
        {
            continue;
        }
        else
        {
            cout << "\tВы произвели неверный ввод, попробуйте еще раз!" << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(unsigned(time(NULL)));

    int GameOption;
    int balance = 1000;
    int* pbalance = &balance;

    while (true)
    {
        cout << "\n\t\t\tДобро пожаловать в казино Q'cas!\n\t\tВам нужно выбрать одну из 3 игр, в которые вы будете играть." << endl << endl;
        cout << "\t\t\t:: 1 - Кости      ::\n\t\t\t:: 2 - Блэкджек ::\n\t\t\t:: 3 - Удачная рулетка  ::" << endl << endl;
        cout << "\t\tВаш кошелек: " << balance << "$" << endl << endl;

        while (true)
        {
            cout << "\n\tОпция: ";
            cin >> GameOption;

            if (GameOption != 1 && GameOption != 2 && GameOption != 3) // выбор игры
            {
                cout << "\tНеверная опция, попробуйте еще раз!" << endl;
            }
            else
            {
                switch (GameOption)
                {
                case 1:
                {
                    Dice(*pbalance);

                    break;
                }
                case 2:
                {
                    Blackjack(*pbalance);

                    break;
                }
                case 3:
                {
                    LuckyRoulette(*pbalance);

                    break;
                }
                 // тут блок дефолт но он мне не нужен
                }

                break;
            } // конец выбора игры
        }

    }
    
    return 0;
}
