/// @description Начальные переменные
#region Help
sTitle = "магазин комьютерной и бытовой техники";
sNickname = "введите ваше имя: ";

sInNickname = "";
limitstr = 10;

cursor = "|";
delay = 20;
alarm[0] = delay;
choice = 0;

glWindow = 0;
#endregion

n = 3;
str[n - 1] = "";
name[n - 1] = "";
count[n - 1] = 0;
cost[n - 1] = 0;

OwnCount[n - 1] = 0;
OwnCost[n - 1] = 0;

var fileProducts = file_text_open_read(working_directory + "products.txt");
var i = 0;

while (!file_text_eof(fileProducts))
{
	str[i] = file_text_readln(fileProducts);
	var res = string_split(str[i], " ");
	name[i] = string(res[0]);
	count[i] = real(res[2]);
	cost[i] = real(res[4]);
	i++;
}
file_text_close(fileProducts);
