// Room: /u/cat/workroom.c

inherit ROOM;

void create()
{
        set("short", "è�Ĺ�����");
        set("long", @LONG
����è�Ĺ�����,�յ�����,ֻ��һ̨����,һ��ˮ����. ǽ�Ϲ���
һ�ſ���ַ�:

                  [37;44m����������������������[0m
                  [37;44m��[33m ˹��ª��,�������ک�[0m
                  [37;44m����������������������[0m

    [35mƽƽ���������氡~~~~~~~~~~~~~~~.[0m

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"down" : "/d/fy/fysquare",
	"west" : "/u/t/tjb/workroom",
	// "out" : "/d/wizard/workroom",
]));
	set("valid_startroom",1);
        set("objects",([
                __DIR__"guo" : 5,
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
