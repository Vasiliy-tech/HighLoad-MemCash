#include <iostream>
#include <stdint.h>
#import <vector>
#import <cstdlib>


using namespace std;
int64_t LIST_SIZE = 10;
struct list {
	list *next;
	int64_t data;
};

list* create_the_first_element() {
	list *first = NULL;
	first = new list;
	first->data = 1;
	first->next = NULL;
	return first;
}

void create_lists (list *first, int64_t count) {
	list *after_first;

	after_first = first;

	for (int i = 2; i <= count; i++) {

		after_first->next = new list;
		after_first = after_first->next;
		after_first->data = i;
		after_first->next = NULL;

	}
}

void print_list(list *my_list) {
    while (my_list) {
        cout << my_list->data << endl;
        my_list = my_list->next;
    }
}

void create_pointer_array(vector<list*> &pointer_array, list* first_element) {
       while (first_element) {
          pointer_array.push_back(first_element);
          first_element = first_element->next;
       }
}

void create_simple_random_array(int64_t* random_array) {
    int64_t i = 0;
    while ( i < LIST_SIZE) {
        bool flag = false;
        int64_t a = rand() % LIST_SIZE;
        for(int64_t j = 0;j < i; j++) {
            if (random_array[j] == a) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            random_array[i] = a;
            i++;
        }
    }
}

void print_random_array(int64_t* random_array){
for(int64_t i = 0; i < LIST_SIZE; i++){
    cout<< random_array[i] << endl;
}
}

void create_beginer_list(vector<list*> pointer_array, int64_t* random_index_array, list* first){
list *after_first;
after_first = first;

for(int64_t i = 1; i < LIST_SIZE; i++) {
    after_first->next = pointer_array[ random_index_array[i] ];
    after_first = after_first->next;
    after_first->next = NULL;
}
}

void print_vector(vector<list*> pointer_array){
for(int64_t i = 0; i < LIST_SIZE; i++){
    cout << pointer_array[i] << endl;
}
}

int main()
{   list* first_elemet;
    first_elemet = create_the_first_element();
    create_lists(first_elemet, LIST_SIZE);

    //print_list(first_elemet);
    //cout << endl;


    vector<list*> pointer_array;
    create_pointer_array(pointer_array, first_elemet);
    //print_vector(pointer_array);
    //print_list(first_elemet);

    int64_t random_index_array[LIST_SIZE];
    create_simple_random_array(random_index_array);
    //print_random_array(random_index_array);


    list* beginer_list;
    beginer_list = pointer_array[random_index_array[0]];
    beginer_list->next = NULL;


    create_beginer_list(pointer_array, random_index_array, beginer_list);

    print_list(beginer_list);
    //print_list(first_elemet);






    //cout << random_array[i] << endl;
    //cout << sizeof(int64_t)<< endl << sizeof(*first_elemet)<<endl<<sizeof(first_elemet->data)<<endl << sizeof(first_elemet->next);

    return 0;
}
