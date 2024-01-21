#include <iostream>
#include <string>
using namespace std;
#define MAX 1000
//设计联系人结构体
struct person{
    //姓名
    string one_name;
    //性别 1:男或2:女
    string one_sex;
    //年龄
    int one_age;
    //电话
    string one_tel;
    //住址
    string  one_address;
};

//设计通讯录结构体
struct contacts
{
    //通讯录中联系人数组
    struct person person_array[MAX];

    //通讯录中联系人个数
    int contacts_size;
};

//菜单界面
void show_menu()
{
    std::cout << "***************************" << std::endl;
    std::cout << "********1.添加联系人********" << std::endl;
    std::cout << "********2.显示联系人********" << std::endl;
    std::cout << "********3.删除联系人********" << std::endl;
    std::cout << "********4.查找联系人********" << std::endl;
    std::cout << "********5.修改联系人********" << std::endl;
    std::cout << "********6.清空联系人********" << std::endl;
    std::cout << "********0.退出通讯录********" << std::endl;
    std::cout << "***************************" << std::endl;
}

void add_person(contacts* cts)
{
    //判断通讯录是否已经满
    if(cts->contacts_size+1>MAX)
    {
        std::cout << "ERROR：通讯录已满，无法添加" << std::endl;
        return;
    }
    else {
        //添加姓名
        string name;
        std::cout << "请输入姓名： " << std::endl;
        std::cin >> name;
        cts->person_array[cts->contacts_size].one_name = name;

        //添加性别
        std::cout << "请选择性别： " << std::endl;
        std::cout << "1:男" << std::endl;
        std::cout << "2:女" << std::endl;
        int sex;
        std::cin >> sex;
        while (true)
        {

            if (sex == 1 )
            {
                cts->person_array[cts->contacts_size].one_sex = "男";
                break;
            }
            else if (sex == 2)
            {
                cts->person_array[cts->contacts_size].one_sex = "女";
                break;
            }
            else
            {
                std::cout << "ERROR：性别有错误，请重新输入" << std::endl;
            }

        }

        //添加年龄
        std::cout << "请输入年龄： " << std::endl;
        int age;
        while (true)
        {
            std::cin >> age;
            if (age > 0 && age < 150)
            {
                cts->person_array[cts->contacts_size].one_age = age;
                break;
            }
            else
            {
                std::cout << "ERROR：年龄有错误，请重新输入";
            }
        }
        //添加电话
        std::cout << "请输入电话： " << std::endl;
        string tel;
        std::cin >> tel;
        cts->person_array[cts->contacts_size].one_tel=tel;

        //添加地址
        std::cout << "请输入家庭地址： " <<std::endl;
        string address;
        std::cin >> address;
        cts->person_array[cts->contacts_size].one_address=address;

        //更新通讯录数量
        cts->contacts_size=cts->contacts_size+1;

        std::cout <<  "您已添加成功" << std::endl;
    }
}

//显示所有联系人
void show_person(contacts* cts)
{
    //判断通讯录中人数是否为0
    if(cts->contacts_size==0)
    {
        std::cout << "ERROR：通讯录为空" << std::endl;
    }
    else
    {
        for(int i=0;i<cts->contacts_size;i++)
        {
            std::cout << "姓名： " << cts->person_array[i].one_name << "\t";
            std::cout << "性别： " << cts->person_array[i].one_sex << "\t";
            std::cout << "年龄： " << cts->person_array[i].one_age << "\t";
            std::cout << "电话： " << cts->person_array[i].one_tel << "\t";
            std::cout << "住址： " << cts->person_array[i].one_address << std::endl;
        }
    }
}

//检测联系人是否存在
int check_person(contacts* cts,string name)
{
    for(int i=0;i<cts->contacts_size;i++)
    {
        if(name==cts->person_array[i].one_name)
        {
            return i;
        }
    }
    std::cout << "ERROR：无此联系人" <<std::endl;
    return -1;
}

//删除指定联系人
void delete_person(contacts* cts,string name)
{
    int pos=check_person(cts,name);
    for(int i=pos;i<cts->contacts_size;i++)
    {
        cts->person_array[i]=cts->person_array[i+1];
    }
    cts->contacts_size--;
}

//清空联系人
void delete_all(contacts* cts)
{
    for(int i=0;i<cts->contacts_size;i++)
    {
        cts->contacts_size=0;
    }
}

//修改联系人
void change_person(contacts* cts)
{
    std::cout<<"请输入您要修改的联系人"<<std::endl;
    string name;
    std::cin >>name;
    int ret= check_person(cts,name);
    if(ret==-1)
    {
        std::cout<<"ERROR：要修改的联系人不存在"<<std::endl;
    }
    else
    {
        //name
        string name;
        std::cout<<"请重新输入联系人姓名： "<<std::endl;
        std::cin>>name;
        cts->person_array[ret].one_name=name;
        //sex
        std::cout<<"请重新输入联系人性别： "<<std::endl;
        std::cout<<"1：男  2：女"<<std::endl;
        int sex=0;
        while(true)
        {
            std::cin >> sex;
            if (sex == 1)
            {
                cts->person_array[ret].one_sex = "男";
                break;
            }
            else if (sex == 2)
            {
                cts->person_array[ret].one_sex = "女";
                break;
            }
            else
            {
                std::cout<<"ERROR：无效输入，请重新输入!"<<std::endl;
            }
        }
        //age
        int age;
        std::cout<<"请重新输入联系人年龄： "<<std::endl;
        std::cin>>age;
        cts->person_array[ret].one_age=age;
        //tel
        string tel;
        std::cout<<"请重新输入联系人电话： "<<std::endl;
        std::cin>>tel;
        cts->person_array[ret].one_tel=tel;
        //address
        string address;
        std::cout<<"请重新输入联系人地址： "<<std::endl;
        std::cin>>address;
        cts->person_array[ret].one_address=address;
    }
}

int main() {

    //创建通讯录变量
    contacts cts;
    //初始化人员个数
    cts.contacts_size=0;

    int select;//创建用户变量
    while (true)
    {
        show_menu();
        std::cout << "请您选择您要作出的选项: " << std::endl;
        std::cin >> select;
        switch (select) {
            case 1://添加联系人
            {
                add_person(&cts);
                std::cout << "是否返回主目录(y/n)" << std::endl;
                string back_bool;
                std::cin >> back_bool;
                if (back_bool == "y") {
                    continue;
                }
                else if(back_bool=="n")
                {
                    break;
                }
            }
            case 2://2.显示联系人
            {
                show_person(&cts);
                std::cout << "是否返回主目录(y/n)" << std::endl;
                string back_bool;
                std::cin >> back_bool;
                if (back_bool == "y") {
                    continue;
                }
                else if(back_bool=="n")
                {
                    break;
                }
            }
            case 3://3.删除联系人
            {
                std::cout << "请输入要删除的联系人的姓名： " <<std::endl;
                string name;
                std::cin >>name;
                if(check_person(&cts,name)==-1)
                {
                    std::cout<< "ERROR：要删除的联系人不存在" <<std::endl;
                }
                else
                {
                    std::cout<< "已找到联系人" <<std::endl;
                    std::cout<< "是否确定删除联系人"<< name <<"(y/n)" << std::endl;
                    string firm_del;
                    std::cin >> firm_del;
                    if(firm_del=="n")
                    {
                        std::cout << "您已取消删除!" <<std::endl;
                        goto FLAG_1;
                    }
                    else if(firm_del=="y")
                    {
                        delete_person(&cts,name);
                    }
                }
                FLAG_1:
                std::cout << "是否返回主目录(y/n)" << std::endl;
                string back_bool;
                std::cin >> back_bool;
                if (back_bool == "y") {
                    continue;
                }
                else if(back_bool=="n")
                {
                    break;
                }
            }
            case 4://4.查找联系人
            {
                std::cout << "请输入您要查找的联系人： " << std::endl;
                string name;
                std::cin >>name;
                int pos=check_person(&cts,name);
                std::cout << "姓名： " << cts.person_array[pos].one_name << "\t";
                std::cout << "性别： " << cts.person_array[pos].one_sex << "\t";
                std::cout << "年龄： " << cts.person_array[pos].one_age << "\t";
                std::cout << "电话： " << cts.person_array[pos].one_tel << "\t";
                std::cout << "住址： " << cts.person_array[pos].one_address << std::endl;
                std::cout << "是否返回主目录(y/n)" << std::endl;
                string back_bool;
                std::cin >> back_bool;
                if (back_bool == "y") {
                    continue;
                }
                else if(back_bool=="n")
                {
                    break;
                }
            }
            case 5://5.修改联系人
            {
                change_person(&cts);
                std::cout<<"联系人已修改成功!"<<endl;
                std::cout << "是否返回主目录(y/n)" << std::endl;
                string back_bool;
                std::cin >> back_bool;
                if (back_bool == "y") {
                    continue;
                }
                else if(back_bool=="n")
                {
                    break;
                }
            }
            case 6://6.清空联系人
            {
                std::cout << "是否确认要清空通讯录(y/n)" <<std::endl;
                string all_del_firm;
                std::cin >>all_del_firm;
                if(all_del_firm=="y")
                {
                    delete_all(&cts);
                }
                else if(all_del_firm=="n")
                {
                    goto FLAG_2;
                }
                FLAG_2:
                std::cout << "是否返回主目录(y/n)" << std::endl;
                string back_bool;
                std::cin >> back_bool;
                if (back_bool == "y") {
                    continue;

                }
                else if(back_bool=="n")
                {
                    break;
                }
            }
            case 0://0.退出通讯录
            {
                std::cout << "是否确定退出(y/n)" << std::endl;
                string back_bool;
                std::cin >> back_bool;
                if (back_bool == "y") {
                    std::cout << "您已退出，欢迎下次使用" << std::endl;
                    break;
                }
                else if(back_bool=="n")
                {
                    continue;
                }

            }
                default:
                    std::cout << "ERROR：选项不合法，请输入正确的选项！" << std::endl;
                continue;

        }
        return 0;
    }
}
