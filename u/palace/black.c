
inherit ROOM;

void create()
{
        set("short", "��ʯ��·");
        set("long", @LONG
����һ���Ժ�ʯ�̳ɵĵ�·����·�����ش���һƬ���֣�����Խ���
��Խ��������������ȴ͸��һ����⣬���ڵ��ϵĺ�ʯ�ϣ��ĵ����¸���
�������
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"intersection",
  "south" : __DIR__"black2",
]));
        set("outdoors", "palace");

        setup();
        replace_program(ROOM);
}

