#ifndef LISTASEQUENCIAL_H
#define LISTASEQUENCIAL_H

class elemento
{
    private:
        int id;
    public:
        elemento(int ID);
        bool set_id(int ID);
        int get_id();
        virtual void imprimir_info() const = 0;
};

class elemento_1 : elemento
{
    public:
        elemento_1();
        void imprimir_info();
};

#endif