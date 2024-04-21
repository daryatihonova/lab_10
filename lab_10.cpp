#include <iostream>
#include <string>
#include <vector>
#include "App.h"


using namespace std;

struct AppDecorator { // Объявление абстрактного класса AppDecorator
    virtual App* decorate(App* app) = 0;
};

struct MobileAppDecorator : public AppDecorator { // Объявление класса MobileAppDecorator, наследуемого от AppDecorator
    App* decorate(App* app) override { // Переопределение виртуального метода decorate
        app->name = "Мобильное " + app->name;
        return app;
    }
};

struct DesktopAppDecorator : public AppDecorator {// Объявление класса DesktopAppDecorator, наследуемого от AppDecorator
    App* decorate(App* app) override {
        app->name = "Настольное " + app->name;
        return app;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    while (true) {
        string name, producer;
        int diskSize;
        double price;

        cout << "Введите имя программы: ";
        cin.ignore();
        getline(cin, name);

        cout << "Введите производителя программы: ";
        getline(cin, producer);

        cout << "Введите размер на диске: ";
        cin >> diskSize;

        cout << "Введите цену программы: ";
        cin >> price;

        App app{ name, producer, diskSize, price };

        int choice;
        cout << "Выберите вид приложения: " << endl;
        cout << "1. Мобильное приложение" << endl;
        cout << "2. Настольное приложение" << endl;
        cin >> choice;

        
        App* decoratedApp;// Объявление указателя для хранения декорированного приложения
        switch (choice) {
        case 1: {
            MobileAppDecorator mobileDecorator;// Создание объекта MobileAppDecorator
            decoratedApp = mobileDecorator.decorate(&app);
            break;
        }
        case 2: {
            DesktopAppDecorator desktopDecorator;// Создание объекта DesktopAppDecorator
            decoratedApp = desktopDecorator.decorate(&app);
            break;
        }
        default:
            cout << "Неправильный выбор" << endl;
            return 1;
        }

        cout << "Приложение: " << decoratedApp->name << endl;

       
        char cont;
        cout << "Продолжить? (y/n): ";
        cin >> cont;
        if (cont == 'n' || cont == 'N') {
            break;
        }
    }

    return 0;

}
