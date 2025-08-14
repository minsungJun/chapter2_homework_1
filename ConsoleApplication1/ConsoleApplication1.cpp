// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#include <iostream>

using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    *p_HPPotion = count;
    *p_MPPotion = count;
    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
}

int main()
{
    cout << "Start";
    int arr[] = { 0, 0, 0, 0 }; // HP, MP, ATK, DEP
    int hp, mp, atk, dep = 0;
    int input = 0;

    int hp_potion = 0;
    int mp_potion = 0;

    while (1) //hp mp 입력
    {
        cout << "Input HP, MP" << endl;

        cin >> hp;
        cin >> mp;

        if (hp <= 50 || mp <= 50)
        {
            cout << "Please enter a number greater than 50" << endl;
            continue;
        }
        else
        {
            arr[0] = hp;
            arr[1] = mp;
            break;
        }
    }


    while (1) //atk, dep 입력
    {
        cout << "Input ATK, DEP (Please enter a number greater than 0)" << endl;

        cin >> atk;
        cin >> dep;

        if (atk <= 0 || dep <= 0)
        {
            cout << "Please enter a number greater than 0" << endl;
            continue;
        }
        else
        {
            arr[2] = atk;
            arr[3] = dep;
            break;
        }
    }
    setPotion(5, &hp_potion, &mp_potion);
    while (1) //메인 입력 흐름
    {
        cout << "=============================================" << endl;
        cout << "1. HP 회복" << endl;
        cout << "2. MP 회복" << endl;
        cout << "3. HP 강화" << endl;
        cout << "4. MP 강화" << endl;
        cout << "5. 공격 스킬 사용" << endl;
        cout << "6. 필살기 사용" << endl;
        cout << "번호를 선택해주세요: " << endl;
        cin >> input;

        switch (input)
        {
        case 1: //hp potion
            if (hp_potion > 0)
            {
                hp_potion--;
                cout << "* HP가 20 회복되었습니다. 포션이 1개 차감됩니다." << endl;
                cout << "남은 HP포션 : " << hp_potion << endl;
                cout << "현재 HP: " << arr[0] << endl;

                arr[0] += 20;
            }
            else
            {
                cout << "* 포션이 부족합니다. (남은 HP포션 : " << hp_potion << ")" << endl;
            }
            break;

        case 2: //mp potion
            if (mp_potion > 0)
            {
                mp_potion--;
                cout << "* MP가 20 회복되었습니다. 포션이 1개 차감됩니다." << endl;
                cout << "남은 MP포션 : " << mp_potion  << endl;
                cout << "현재 MP: " << arr[1] << endl;

                arr[1] += 20;
            }
            else
            {
                cout << "* 포션이 부족합니다. (남은 MP포션 : " << mp_potion << ")" << endl;
            }
            break;

        case 3: //hp reinforce
            arr[0] *= 2;
            cout << "* HP가 2배로 증가되었습니다." << endl;
            cout << "현재 HP: " << arr[0] << endl;
            break;

        case 4: //mp reinforce
            arr[1] *= 2;
            cout << "* MP가 2배로 증가되었습니다." << endl;
            cout << "현재 MP: " << arr[1] << endl;
            break;

        case 5: //attack
            if (arr[1] >= 50)
            {
                arr[1] -= 50;
                cout << "* 스킬을 사용하여 MP가 50 소모되었습니다." << endl;
                cout << "현재 MP: " << arr[1] << endl;
            }
            else
            {
                cout << "스킬 사용이 불가합니다." << endl;
                cout << "현재 MP: " << arr[1] << endl;
            }
            
            break;

        case 6: //skill
            arr[1] /= 2;
            cout << "* 스킬을 사용하여 MP가 50% 소모되었습니다." << endl;
            cout << "현재 MP: " << arr[1] << endl;

            break;
        case 7:
            cout << "프로그램을 종료합니다" << endl;
            return 0;
        }

    }
    return 0;
}



// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
