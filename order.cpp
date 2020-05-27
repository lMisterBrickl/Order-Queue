#include <iostream>
#include <string.h>
#include "node.cpp"
#include <fstream>
using namespace std;

class OrderQueue {
    private:
        Node *first=NULL;
        Node *last=NULL;
    public:

        Node* get_first(){
            return this->first;
        }
        void set_first(Node* new_first){
            this->first=new_first;
        }

        Node* get_last(){
            return this->last;
        }

        void set_last(Node* new_last){
            this->last=new_last;
        }

        void add(char *name_client){
             Node *nnode=new Node();
             nnode->set_client(name_client);
             nnode->set_next(NULL);

             if(this->get_last()==NULL){
                this->set_first(nnode);
                this->set_last(nnode);
             }
             else{
                this->get_last()->set_next(nnode);
                this->set_last(nnode);
             }
        this->save_in_file();
        }

        void remove_first(){
            if(this->get_first()!=NULL){
                this->set_first(this->get_first()->get_next());
                this->save_in_file();
            }
        }

        void show(){
            cout<<"Coada Curenta:"<<endl;
            if(this->get_first()==NULL){
                cout<<"Coada este goala"<<endl;
            }

            else{
                Node *curr_node=this->get_first();
                while(curr_node!=NULL){
                    cout<<curr_node->get_client()<<endl;
                    curr_node=curr_node->get_next();
                }
            }

        }

        void create_from_file(){
            ifstream f;
            f.open("Coada.txt");
            char nume[30];
            while(f>>nume){
                this->add(nume);
            }
            f.close();

        }

        void save_in_file(){
            ofstream g;
            g.open("Coada.txt");
            Node *curr_node=this->get_first();
            while(curr_node!=NULL){
                    g<<curr_node->get_client()<<endl;
                    curr_node=curr_node->get_next();
                }
            g.close();

        }


};
