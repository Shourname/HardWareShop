/// @description Визуал

// Установление интерфейса

draw_set_color(c_black);
draw_set_font(fMain);

if (glWindow == 0)
{
	draw_text(350, 50, sTitle);
	draw_text(430, 300, sNickname);
	draw_text(x - 232, y + 320, "затем нажмите кнопку ввода");

	// Ввод имени
	draw_set_color(c_green);
	draw_text(x + 100, y + 260, message + cursor);
}

if (glWindow == 1)
{
	var c = 400, c1 = 700, j = 0;
	
	draw_text_ext(50, 100, "название товара - кол-во на складе | стоимость за штуку || кол-во в корзине (+-) сумма", 34, 600);
	draw_text_ext(650, 100, "после того, как вы выбрали подходящие товары нажмите клавишу ввода", 34, 600);
	switch(choice)
	{
		case 0:
			draw_text(100, c, str[0]); draw_text(c1, c, "||"); draw_sprite(splusamdminus, 2, c1 + 200, c + 18); draw_sprite(splusamdminus, 3, c1 + 270, c + 18);
			draw_text(100, c + 100, str[1]); draw_text(c1, c + 100, "||"); draw_sprite(splusamdminus, 0, c1 + 200, c + 118); draw_sprite(splusamdminus, 1, c1 + 270, c + 118);
			draw_text(100, c + 200, str[2] ); draw_text(c1, c + 200, "||"); draw_sprite(splusamdminus, 0, c1 + 200, c + 218); draw_sprite(splusamdminus, 1, c1 + 270, c + 218);
			draw_text(c1 + 90, c + 5, string(OwnCount[choice]));
			draw_text(c1 + 350, c + 5, string(OwnCost[choice]));
			break;
		case 1:
			draw_text(100, c, str[0]); draw_text(c1, c, "||"); draw_sprite(splusamdminus, 0, c1 + 200, c + 18); draw_sprite(splusamdminus, 1, c1 + 270, c + 18);
			draw_text(100, c + 100, str[1]); draw_text(c1, c + 100, "||"); draw_sprite(splusamdminus, 2, c1 + 200, c + 118); draw_sprite(splusamdminus, 3, c1 + 270, c + 118);
			draw_text(100, c + 200, str[2] ); draw_text(c1, c + 200, "||"); draw_sprite(splusamdminus, 0, c1 + 200, c + 218); draw_sprite(splusamdminus, 1, c1 + 270, c + 218);
			draw_text(c1 + 90, c + 105, string(OwnCount[choice]));
			draw_text(c1 + 350, c + 105, string(OwnCost[choice]));
			break;
		case 2:
			draw_text(100, c, str[0]); draw_text(c1, c, "||"); draw_sprite(splusamdminus, 0, c1 + 200, c + 18); draw_sprite(splusamdminus, 1, c1 + 270, c + 18);
			draw_text(100, c + 100, str[1]); draw_text(c1, c + 100, "||"); draw_sprite(splusamdminus, 0, c1 + 200, c + 118); draw_sprite(splusamdminus, 1, c1 + 270, c + 118);
			draw_text(100, c + 200, str[2] ); draw_text(c1, c + 200, "||"); draw_sprite(splusamdminus, 2, c1 + 200, c + 218); draw_sprite(splusamdminus, 3, c1 + 270, c + 218);
			draw_text(c1 + 90, c + 205, string(OwnCount[choice]));
			draw_text(c1 + 350, c + 205, string(OwnCost[choice]));
			break;
	}
}