inherit ROOM;
void create()
{
        set("short", "���ƴ�·");
        set("long", @LONG
���Ļ���·����������չ��·�ߵ�é�ݰ�С���ƾɣ��ֱߵ�����ɢ����
������Ż�ĸ�����·�ϵ�������Ƽ��ݣ���ƶ���������ϵ�ƣ��������ż����һ
������ɫ����֮�ˣ����ڱǴҴҶ���������մ��һ�������һ���ȳ��ĸ���ζ��
�������������ɢ����������������������С�ƹ����ӾƵ�ζ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"tuji",
  "south" : __DIR__"zuisheng",
  "west"  : __DIR__"wgate",
  "east"  : __DIR__"wcloud4",
]));

        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
