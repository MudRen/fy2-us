inherit ROOM;
void create()
{
        set("short", "���ƴ�·");
        set("long", @LONG
���Ļ���·����������չ��·�ߵ�é�ݰ�С���ƾɣ��ֱߵ�����ɢ����
������Ż�ĸ�����·�ϵ�������Ƽ��ݣ���ƶ���������ϵ�ƣ��������ż����һ
������ɫ����֮�ˣ����ڱǴҴҶ���������մ��һ���������·�ϲ�İ����ײ�
����ӭ�ŷ��ż��ڱ�Ƥľ�ף���·����İ���ľ�����к�����һƬ�����������
������������ʲô��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"afa",
  "south" : __DIR__"ansheng",
  "west"  : __DIR__"wcloud5",
  "east"  : __DIR__"wcloud3",
]));

        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
