inherit ROOM;

void create()
{
	set("short","�շ���");
	set("long","������...\n");
	setup();
}

void init()
{
	if (!wizardp(this_player()))
	add_action("block_cmd","",1);
}

int block_cmd()
{
	return 1;
}
