// Room: /d/chuenyu/dustyroad2.c

inherit ROOM;

void create()
{
        set("short", "����·��");
        set("long", @LONG
����ͨ��ɽ���С·������������һ��СС��ס�ң�
ס�ҵĺ�����һ���ܴ�Ļ�԰����԰���кܶ�Сͯ����ˣ��
������ͨ��С��ķ���
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"dustyroad3",
  "south" : __DIR__"dustyroad",
  "north" : __DIR__"sunnyroad",
]));
        set("outdoors", "chuenyu");

        setup();
        replace_program(ROOM);
}

