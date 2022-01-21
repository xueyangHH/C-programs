#include "employee.h"
EMPLOYEE* list_of_employees=NULL;

void printEmployee(EMPLOYEE e){
    printf("Name: %s", e.name);
    printf(", ID: %d\n", e.id);
    if (e.payments == NULL) {
      printf("No Payments..\n");
    } else {
      printf("--------------------\n");
      printf("Date                    Amount\n");
      printf("----                    ------\n");
      PAYMENT* currentp = e.payments;
      while (currentp != NULL) {
        printf("%s              %f\n", currentp->date, currentp->amount);
        currentp = currentp->next;
      }
    }
}

void addEmployee(int e_id, char* e_name){
    EMPLOYEE* ep;
    ep = (EMPLOYEE*) malloc(sizeof(EMPLOYEE));
    ep->id = e_id;
    ep->name = e_name;
    ep->next = list_of_employees;
    list_of_employees = ep;
    ep->payments = NULL;
}

void printEmployees(){
  EMPLOYEE* current = list_of_employees;
  if (current == NULL) {
    printf("The list is empty..\n");
  }
  while (current != NULL) {
    printEmployee(*current);
    printf("===================================\n");
    current = current->next;
  }
}

int addPayment(int e_id, char* p_date, float p_amount){
    PAYMENT* p;
    p = (PAYMENT*) malloc(sizeof(PAYMENT));
    p->amount = p_amount;
    p->date = p_date;
    EMPLOYEE* current = list_of_employees;
    while (current->id != e_id) {
      if (current->next == NULL) {
        return 0;
      } else {
        current = current->next;
      }
    }
    p->next = current->payments;
    current->payments = p;
    return 1;
}

int deleteEmployee(int e_id, char* e_name){
    EMPLOYEE* current = list_of_employees;
    EMPLOYEE* previous = list_of_employees;
    while (current->id != e_id) {
      if (current->next == NULL) {
        return 0;
      } else {
        previous = current;
        current = current->next;
      }
    }
    if (current == list_of_employees) {
      list_of_employees = list_of_employees->next;
    } else {
      previous->next = current->next;
    }
    free(current);
    return 1;
}