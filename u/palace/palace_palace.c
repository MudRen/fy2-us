 
inherit ROOM;

void create()
{
        set("short", "���˶�");
        set("long", @LONG
����ʯ����ֻ����ľ�״У��滨���ף�һ���������ӻ�ľ�
к��ʯ϶֮�¡�������֮��������Ϫк��ʯ���ƣ���ʯΪ����
�������ӣ�ʯ�����ۣ��������¡�
LONG
        );
        set("exits", ([ 
  "westdown" : __DIR__"palace_front",
  "eastup" : __DIR__"square",
]));
        set("objects", ([
               __DIR__"npc/master2" : 1,
       ]) );
        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}

