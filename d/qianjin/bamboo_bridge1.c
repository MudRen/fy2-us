inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�����Ͻ���Ǿޱ��ľ�㡢��÷����ȸ�������������ɡ����ڡ�������֡�������
���桢�ٺϡ������ޡ������ޡ����ؽ�����֦ĵ�����࣬����ö�١�������֮ʱ����
���������Զ�����ߣ���ֲ������ݡ�һ��δл��һ���ֿ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"garden",
  "northwest" : __DIR__"bamboo_bridge2",
]));
        set("objects", ([
        __DIR__"npc/gongzi" : 1,
                        ]) );
	set("outdoors","fengyun");
        setup();
        replace_program(ROOM);
}
