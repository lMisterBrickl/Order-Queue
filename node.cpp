#include <iostream>
#include <string.h>

using namespace std;

class Node {
    private:
        Node* next;
        char client_name[30];
    public:
        Node* get_next(){
            return this->next;
        }

        void set_next(Node* new_node){
            this->next=new_node;
        }

        char* get_client(){
            return this->client_name;
        }

        void set_client(char* new_client){
            strcpy(this->client_name,new_client);
        }
};
