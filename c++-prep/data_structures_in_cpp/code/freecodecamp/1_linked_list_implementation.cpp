#include <iostream>
#include <string>
#include <memory>

using namespace std;

    struct Node{

        int data;
        std::unique_ptr<Node> next_node;

        Node(int input_data){
            data = input_data;
            next_node = nullptr;
        }

        ~Node(){
            cout << "Node object destroyed\n";
        }
    };

struct LinkedList{

    std::unique_ptr<Node> head; 

    LinkedList(){
        head = nullptr;
    }

    ~LinkedList(){
        cout << "LinkedList object destroyed\n";
    }

    void add_element_to_beginning(int value_to_add){

        unique_ptr<Node> temp = make_unique<Node>(value_to_add);

        if(head){
            temp->next_node = move(head);
            head = move(temp);
        } else {
            head = move(temp);
        }

        print_linked_list();
    }

    void add_element_to_tail(int value_to_add){
        
        if(head){
            Node* temp;

            for(temp = head.get(); temp->next_node != nullptr; temp = temp->next_node.get());

            temp->next_node = make_unique<Node>(value_to_add);            
            
        } else {
            head = make_unique<Node>(value_to_add);
        }

        print_linked_list();
    }

    void add_element_in_middle(int value_to_add, int position_to_add_value_in){
        
        /* Confirm head is not empty.  */

        if(head){

            if(position_to_add_value_in == 0){
                add_element_to_beginning(value_to_add);
                return;
            }

            /* Find number of elements in the list */
            int number_of_elements_in_list = -1;
            for(const Node* temp = head.get(); temp != nullptr ; temp = temp->next_node.get()){
                number_of_elements_in_list++;
            }

            if(position_to_add_value_in == (number_of_elements_in_list + 1)){
                add_element_to_tail(value_to_add);
                return;
            }

            if(position_to_add_value_in <= number_of_elements_in_list){

                Node* prev_temp;
                int current_position_in_list = 0;
                Node* temp = head.get();

                for(; temp->next_node != nullptr ; temp = temp->next_node.get()){

                    if(current_position_in_list < position_to_add_value_in){
                        prev_temp = temp;
                        current_position_in_list++;
                    } else {
                        break;
                    }
                }

                unique_ptr<Node> temp_obj_new_value = make_unique<Node>(value_to_add);
                temp_obj_new_value->next_node = move(prev_temp->next_node);
                
                //* temp_obj_new_value->next_node = std::unique_ptr<Node>(temp); --> NOTE: Error. Because object owned by temp here is already owned by a unique_ptr (either head or another unique_ptr as temp traverses through the list). We attempt to assign the object owned by temp to another unique_ptr temp_obj_new_value. This creates double ownership. When either unique_ptr gets deleted the coressponding Node object also gets deleted.  

                prev_temp->next_node = move(temp_obj_new_value);

                print_linked_list();

                return;

            } else {
                cout << "Adding in middle failed\n";
                return;
            }

        } else {
            cout << "Adding in middle failed\n";
            return;

        }
    }

    void remove_element_at_head(){     
        
        /* Try to remove element at head iff there is atleast 1 element in head. */
        if(head){

            Node* prev_temp; Node* temp;

            temp = head.get();

            /* Determine if there is only one element in the list or there are more elements. */

            if(temp->next_node){

                head = move(head->next_node);

            } else {
                /* There is only one element. Hence, simply deallocate head and move on.*/

                head.reset();
            }
        }

        print_linked_list();
    }

    void remove_element_at_tail(){
        
        /* Check list not empty. */
        if(head){
            /* Check if list has more than one element */

            if(head->next_node){

                /* List has more than one element. */

                Node* temp = head.get();
                Node *prev_temp;
                
                while(temp->next_node){
                    prev_temp = temp;
                    temp = temp->next_node.get();
                }

                prev_temp->next_node.reset();                

            } else {
                /* There is only one element. Hence, simply deallocate head and move on.*/

                head.reset();
            }
        }

        print_linked_list();
    }

    void remove_element_in_middle(int position_to_remove){

        if(position_to_remove == 0){
            remove_element_at_head();
            return;
        }

        int number_of_elements_in_list = 0;

        for(Node* temp = head.get(); temp != nullptr; temp = temp->next_node.get()){
            number_of_elements_in_list++;
        }

        if(position_to_remove > (number_of_elements_in_list - 1)){
            cout << "Removal failed.\n";
            return;
        } else {

            int current_position_in_list = -1;
            Node* prev_temp;
            for(Node* temp = head.get(); temp->next_node != nullptr; temp = temp->next_node.get()){
                current_position_in_list++;
                
                if(current_position_in_list == position_to_remove){
                    prev_temp->next_node = move(temp->next_node);
                    print_linked_list();
                    return;
                }

                prev_temp = temp;
            }
        }

    }

    void print_linked_list(){

        cout << "#####################################################################################\n";

        for(const Node* temp = head.get(); temp != nullptr; temp = temp->next_node.get()){
            cout << "Node address: " << temp << endl;
            cout << "Data: " << temp->data << endl;
            cout <<"Next: " << temp->next_node.get() << endl << endl << endl;
        }
    }

};

int main(){

    LinkedList linked_list_obj;

    linked_list_obj.add_element_to_beginning(1);
    linked_list_obj.add_element_to_tail(2);
    linked_list_obj.add_element_to_tail(3);

    linked_list_obj.add_element_in_middle(7, 2);

    linked_list_obj.add_element_in_middle(15, 0);

    linked_list_obj.add_element_in_middle(30, 5);

    linked_list_obj.add_element_in_middle(30, 7);

    linked_list_obj.remove_element_in_middle(2);

    linked_list_obj.remove_element_in_middle(3);

    linked_list_obj.remove_element_in_middle(4);
    
    linked_list_obj.remove_element_at_head();

    linked_list_obj.remove_element_at_tail();


	return 0;
}