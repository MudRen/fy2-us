// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���޵����԰�", ({ "board" }) );
	set("location", "/u/t/tjb/workroom");
	set("board_id", "tjb_b");
	set("long","����һ���������Լ��µ����԰塣\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
