struct Node* i = L;
int count = 1;
struct Student x = i->Next->Element;
while(i->Next != NULL) {
float avg = (x.R1 + x.R2 + x.R3)/3;
printf("%2d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n", count, x.ID, x.Name, x.R1, x.R2, x.R3, avg);
i = i->Next;
count++;
}