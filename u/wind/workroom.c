inherit ROOM;
#include <ansi.h>

void create()
{	
set("short", "��Ĺ�����");
set("long", @LONG	
�����Ƿ�Ĺ����ҡ���ܰ�������ڷ�����Ʈ����һ̨���ڲ����������˵ع�����
������һ��Ƭ�յأ���˵��Ϊ���������Ԥ���ġ����(shelf) ��ȫ��С˵������
һ���Ƿ���Լ�����Ʒ��ǽ����һ������(duilian).
LONG	);	
set("valid_startroom",1);
set("no_steal", "1");
	set("exits", ([
		"sh" : "/d/shenlong/wuchang",
		"ts" : "/d/taishan/fengchan",
		"sl" : "/d/shaolin/dxbdian",
		"td" : "/d/city2/dating",
		"bt" : "/d/baituo/dating",
		"wg" : "/d/wudang/sanqingdian",
		"xx" : "/d/xingxiu/xxh2",
		"th" : "/d/taohua/dating",
		"hg" : "/d/city2/tian_anm",
		"gb" : "/d/city/gbxiaowu",
		"wz" : "/d/wizard/wizard_room",
		"ct" : "/d/city/guangchang",
		"qz" : "/d/quanzhou/zhongxin",
		"hs" : "/d/huashan/buwei1",
		"lj" : "/d/lingjiu/damen",
		"li" : "/d/city2/tingyu",
	]));

set("item_desc", ([
		"shelf" : HIC "\n��ӯ���������ܣ����������Ĺҡ�\n" NOR,
		"duilian" : HIG "\n����һ�����������\n" NOR + HIC "����һǻȼ�յİ���\n" NOR,
	]));
setup();
}

