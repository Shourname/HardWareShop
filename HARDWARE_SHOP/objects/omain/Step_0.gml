/// @description Получение иинформации
if (string_length(keyboard_string) < limitstr) message = keyboard_string; else keyboard_string = message;

if (glWindow == 0)
{
	if (keyboard_check_pressed(vk_enter)) 
	{ 
		glWindow = 1;
		sInNickname = message;
	}
}

if (glWindow == 1)
{
	if (keyboard_check_pressed(vk_down)) choice++;
	if (keyboard_check_pressed(vk_up)) choice--;
	if(choice > n - 1) choice = n - 1; if (choice < 0) choice = 0;
	
	if(OwnCount[choice] < 0) OwnCount[choice] = 0; if (OwnCount[choice] > count[choice]-1) OwnCount[choice] = count[choice];
	if (keyboard_check_pressed(vk_left)) OwnCount[choice]--;
	if (keyboard_check_pressed(vk_right)) OwnCount[choice]++;
	
	OwnCost[choice] = OwnCount[choice] * cost[choice];
	
	if (keyboard_check_pressed(vk_enter)) 
	{
		var sum = OwnCost[0] + OwnCost[1] + OwnCost[2];
		var fileCheque = file_text_open_write(working_directory + "cheque.txt");
		file_text_write_string(fileCheque, "Уважаймый, " + sInNickname + ", вы приобрели: ");
		file_text_writeln(fileCheque);
		file_text_write_string(fileCheque, name[0] + " " + string(OwnCount[0]) + " на сумму: " + string(OwnCost[0]));
		file_text_writeln(fileCheque);
		file_text_write_string(fileCheque, name[1] + " " + string(OwnCount[1]) + " на сумму: " + string(OwnCost[1]));
		file_text_writeln(fileCheque);
		file_text_write_string(fileCheque, name[2] + " " + string(OwnCount[2]) + " на сумму: " + string(OwnCost[2]));
		file_text_writeln(fileCheque);
		file_text_write_string(fileCheque, "Итоговая сумма: " + string(sum));
		file_text_close(fileCheque);
	}
}
