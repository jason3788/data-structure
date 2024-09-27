#include <iostream>
using namespace std;

class polyll {
private:
    struct polynode {
        float coeff;
        int exp;
        polynode* next;
    } *head;

public:
    polyll();
    void poly_append(float c, int e);
    void display_poly();
    void poly_add(polyll& l1, polyll& l2);
};
polyll::polyll()
{
    head=NULL;
}
void polyll::poly_append(float c, int e)
{
    polynode *newnode;
    polynode *cur =head;
    if (head == NULL) {
        newnode = new polynode;
        head = newnode;
    }
    else {
        while (cur->next != NULL){
        	cur = cur->next;
		}
        newnode = new polynode;
        cur->next = newnode;
    }
    newnode->coeff = c;
    newnode->exp = e;
    newnode->next = NULL;
}
void polyll::display_poly()
{
    polynode* temp = head;
    int f = 0;
    cout << endl; 
	while (temp != NULL) { if (f != 0) { if (temp->coeff > 0)
                cout << " + ";
            else
                cout << " "; } if (temp->exp != 0)
            cout << temp->coeff << "x^" << temp->exp;
        else
            cout << temp->coeff;
        temp = temp->next;
        f = 1;
    }
}
void polyll::poly_add(polyll& l1, polyll& l2)
{
    polynode *cur3;
    polynode *cur1, *cur2;
    cur1 = l1.head;
    cur2 = l2.head;
    while (cur1 != NULL && cur2 != NULL) {
        if (head == NULL) {
            head = new polynode;
            cur3 = head;
        }
        else {
            cur3->next = new polynode;
            cur3 = cur3->next;
        }
		
		 
        if (cur1->exp == cur2->exp) {
            cur3->coeff = cur1->coeff + cur2->coeff;
            cur3->exp = cur1->exp;
            cur1 = cur1->next;
            cur2 = cur2->next;
       }
        else if(cur1->exp > cur2->exp) {
                cur3->coeff = cur1->coeff;
                cur3->exp = cur1->exp;
                cur1 = cur1->next;
        }
        else {
            cur3->coeff = cur2->coeff;
            cur3->exp = cur2->exp;
            cur2 = cur2->next;
        }      
    }
    
    while (cur1 != NULL) {
        if (head == NULL) {
            head = new polynode;
            cur3 = head;
        }
        else {
            cur3->next = new polynode;
            cur3 = cur3->next;
        }
        cur3->coeff = cur1->coeff;
        cur3->exp = cur1->exp;
        cur1 = cur1->next;
    }
    while (cur2 != NULL) {
        if (head == NULL) {
            head = new polynode;
            cur3 = head;
        }
        else {
            cur3->next = new polynode;
            cur3 = cur3->next;
        }
        cur3->coeff = cur2->coeff;
        cur3->exp = cur2->exp;
        cur2 = cur2->next;
    }
}

int main()
{
    polyll p1;
    p1.poly_append(1.4, 5);
    p1.poly_append(1.5, 4);
    p1.poly_append(1.7, 2);
    p1.poly_append(1.8, 1);
    p1.poly_append(1.9, 0);
    cout << "\nFirst polynomial:";
    p1.display_poly();
    polyll p2;
    p2.poly_append(1.5, 6);
    p2.poly_append(2.5, 5);
    p2.poly_append(-3.5, 4);
    p2.poly_append(4.5, 3);
    p2.poly_append(6.5, 1);
    cout << "\nSecond polynomial:";
    p2.display_poly();
    polyll p3;
    p3.poly_add(p1, p2);
    cout << "\nResultant polynomial: ";
    p3.display_poly();
}
