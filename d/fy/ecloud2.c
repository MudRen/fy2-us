inherit ROOM;
void create()
{
        set("short", "���ƴ�·");
        set("long", @LONG
�����Ƿ��Ƴ������̾��������߻켯֮�����������Ǵ�ٹ��ˣ����Ƿ������䣬
ֻҪ����������Ǯ����������ͻ��ܵ�������к����κ��㲻֪�����£��������
��һ�£�������֪�����˾Ų���ʮ���������������˵ģ�����ģ�����ߵģ�����
�ģ���ҩ��...��Ӧ�о��С�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"ecloud3",
  "west" : __DIR__"ecloud1",
  "north": __DIR__"bupu",
  "south": __DIR__"jijian",
]));
        set("objects", ([
        __DIR__"npc/fatman" : 1,
			]) );

        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
