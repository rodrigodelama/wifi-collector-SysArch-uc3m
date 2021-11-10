/**
 * Gorka Bernad - 100451457@alumnos.uc3m.es
 * Rodrigo De Lama - 100451775@alumnos.uc3m.es
 * 
 * main.h:
 * - declares the main function, the printing of the menu, and another number check, for the menu selection
 * - it is used as the main interface to the programme
 */

#ifndef MAIN_H
#define MAIN_H

int main ();
int ask_num(int min, int max, char message[]);
void print_menu()
{
	printf("[2021] SUCEM S.L. Wifi Collector\n");
	printf("  [ 1] wificollector_quit\n");
	printf("  [ 2] wificollector_collect\n");
	printf("  [ 3] wificollector_show_data_one_network\n");
	printf("  [ 4] wificollector_select_best\n");
	printf("  [ 5] wificollector_delete_net\n");
   	printf("  [ 6] wificollector_sort\n");
   	printf("  [ 7] wificollector_export\n");
   	printf("  [ 8] wificollector_import\n");
   	printf("  [ 9] wificollector_display\n");
   	printf("  [ 10] wificollector_display_all\n");
}

#endif
