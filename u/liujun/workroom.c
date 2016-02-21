// Room: workroom.c
// CLEANSWORD

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
	�����������Ĺ����ҡ�������ں����ģ���һֻ�����˰�ߵĵ��ݹ���
���е�����ȥ���ذ����ʧ�ޣ�����ȥ֨ѽ֨ѽ���졣һ�Ѷ���һ���ȵĵ���б
����ǽ�Ǳߡ����϶����˸��ָ����������õĴ�����⡣��Щ�Ѿ����˺þã���
��ʼ��ù�����ˡ�
LONG
	);

	set("objects", ([
//		__DIR__"gun" :    1,
//		__DIR__"mianju" : 1
	]));

	set("valid_startroom",1);

	set("exits", ([
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
	]));

	setup();
	replace_program(ROOM);
}

