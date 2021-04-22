Part1
$ cd YPushkareeev/workspace/projects //создаем директорию с этой лабой
  $ mkdir lab02.1 | cd lab02.1  //создаем директорию с этой лабой и перемещаемся в нее
  $ git init //создаем локальный репозиторий
  Вывод: Initialized empty Git repository in /home/snoreoh/snoreoh/workspace/projects/lab02.1/.git/ 
  $ git remote add origin https://github.com/snoreoh/lab02.1.git  //устанавливаем подключение к удаленному репоззиторию 
  $ touch README.md    //создаем файл 
  $ git add README.md  // добавляем в локальный репозиторий
  $ git commit -m"added README.md"  //комиттим и заливаем его в удаленный репозиторий на ветку master
  $ git push origin master
   $ cat > example/hello_world.cpp <<EOF //перегрузка потока вывода/ввода
  Ввод:  
  > #include <iostream>
  > 
  > using namespace std;
  > 
  > int main(int argc, char** argv)
  > {
  >   cout<< "Hello world!"<< endl;
  > }
  > EOF
   $ git add .//добавление копии в локальный репозиторий
     $ git commit -m"added hello_world.cpp"//коммит с осмысленным сообщением
  $ allias edit=nano
  $ edit hello_world.cpp 
>#include <iostream>
>
>using namespace std;
>
>int main(int argc, char** argv)
>{
> string str;
> cout << "Your name:";
>  getline(cin, str);
>  cout<< "Hello world "<< str <<endl;
>
>  return 1;
>}// изменение исходного кода
$ git commit -m"hello_world.cpp has been changed" -a  // -a позволяет не добавлять файл повторно, мы индексируем изменение.
$ git push origin master

Part 2
$ git сheckout -b patch1  //создаем новую ветку и переходим на нее

//изменяем код в ветке patch1
$ edit hello_world.cpp
>#include <iostream>
>#include <string>
>
>int main(int argc, char** argv)
>{
>  std::string str;
>  std::cout << "Your name:";
>  getline(std::cin, str); 
>  std::cout<< "Hello world  from "<< str <<endl; // out'll be: "Hello world form <name>"
>
>  return 1;
>}
//коммитим её в удалённый репозиторий
 $ git commit -m"some new updates to hello_world.cpp"
   $ git push origin patch1 
   Pull-reques создал 
  
  #include <iostream>
#include <string>

//добавляем комментарии в коде ветки 
int main(int argc, char** argv)
{
  std::string str;
  std::cout << "Your name:";
  getline(std::cin, str); 
  std::cout<< "Hello world  from "<< str <<endl; // out'll be : Hello world for <name>

  return 1;
}
//Коммитим и пушим
$ edit hello_world.cpp 
  $ git commit -m"some more new updates to hello_world.cpp" -a
  $ git push origin patch1
  
  
   $ git checkout master
  $ git merge patch1  //мержим master и patch1
  $ git push origin master
  $ git push origin :patch1  //удаляем patch1 в удаленном репозитории
  
  //локально выполняем пуш
  $ git pull origin master //загружаем файл в локальный репозиторий
   $ git log //смотрим историю коммитов
     $ git branch -d patch1 //удаляем ветку в локальном репозитории
 
 Part3
 
 $ git checkout -b patch2
  $ clang-format -i -style=Chromium hello_world.cpp
    $ git commit commit -m"changed code style" -a
  $ git push origin patch2
  
  //Изменяем язык и расставляем знаки препинания
  include <iostream>
#include <string>

int main(int argc, char** argv)
{
  std::string str;
  std::cout << "Your name:";
  getline(std::cin, str); 
  std::cout<< "Hello world  from "<< str <<endl; // Вывод должен выглядеть: Hello world for <name>

  return 1;
}

$ git checkout master
  $ git pull origin master
  $ git checkout patch2
  $ git rebase master //пытаемся объединить изменения из одной ветки с изменениями в другой ветке
  $ git add hello_world.cpp  //устраняем конфликты вручную 
  $ rebase --continue //объединяем изменения, сделанные в одной ветке, с другой веткой
  
   $ git push --force origin patch2
   
   //Мёржим 
     $ git checkout master
  $ git merge patch2
