inherit ROOM;

void create()
{
        set("short", "�����㳡");
        set("long", @LONG
�����������ǵ����Ĺ㳡.
����ʯ����ֻ����ľ�״У��滨���ף�һ���������ӻ�ľ�
к��ʯ϶֮�¡�������֮��������Ϫк��ʯ���ƣ���ʯΪ����
�������ӣ�ʯ�����ۣ��������¡�
LONG
        );
        set("exits", ([
  "westdown" : __DIR__"palace_palace",
]));
        set("objects", ([
               __DIR__"npc/liling" : 1,
       ]) );
        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}
