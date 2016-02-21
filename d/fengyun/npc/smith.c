#include <ansi.h>
inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg);

void create()
{
        set_name("������", ({ "zhang" }) );
        set("gender", "����" );
        set("age", 52);
        set("long","������һ��������������鴫��������������������ã�\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{	
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_ding", "ding");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "����������������˵������λ" + RANK_D->query_respect(ob)
                                + "��Ҫʲô��\n");
                        break;
                case 1:
                        say( "������������ˮ˵������λ" + RANK_D->query_respect(ob)
                                + "����̫æ�ˣ��ﲻ���㡣\n");
                        break;
        }
}

int do_ding(string arg)
{
	string ctype, cname, ccolor, cid;
	object ob, me, gold;
	string id,newfile,filename;
        me = this_player();
	id = me->query("id");
        if(!arg || sscanf(arg,"%s %s %s %s",ctype,ccolor,cname,cid ) != 4)
        return notify_fail("ָ���ʽ��ding <type> <color> <name> <English name>\n");
	if(me->is_busy())
	return notify_fail("����һ��������û����ɡ�\n");
	if((int)me->query("created_item") >= 3)
	return notify_fail("���Ѿ�ӵ��̫��������Ʒ�ˡ�\n");
	gold = present("gold_money", this_player());
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < 1)
        return notify_fail("������û���������ӡ�\n");
	if( !check_legal_name(cname))
	return notify_fail("");
        if( !check_legal_id(cid))
        return notify_fail("");

	if( ccolor != "$BLK$" && 
	    ccolor != "$NOR$" &&
            ccolor != "$RED$" &&
            ccolor != "$GRN$" &&
            ccolor != "$YEL$" &&
            ccolor != "$BLU$" &&
            ccolor != "$MAG$" &&
            ccolor != "$CYN$" &&
            ccolor != "$WHT$" &&
            ccolor != "$NOR$" &&
            ccolor != "$HIR$" &&
            ccolor != "$HIG$" &&
            ccolor != "$HIY$" &&
            ccolor != "$HIB$" &&
            ccolor != "$HIM$" &&
            ccolor != "$HIC$" &&
            ccolor != "$HIW$" 
	)
	return notify_fail("��֪��Ҫʲô��ɫ��\n");
	cname = ccolor + cname;
        cname = replace_string(cname, "$BLK$", BLK);
        cname = replace_string(cname, "$RED$", RED);
        cname = replace_string(cname, "$GRN$", GRN);
        cname = replace_string(cname, "$YEL$", YEL);
        cname = replace_string(cname, "$BLU$", BLU);
        cname = replace_string(cname, "$MAG$", MAG);
        cname = replace_string(cname, "$CYN$", CYN);
        cname = replace_string(cname, "$WHT$", WHT);
        cname = replace_string(cname, "$HIR$", HIR);
        cname = replace_string(cname, "$HIG$", HIG);
        cname = replace_string(cname, "$HIY$", HIY);
        cname = replace_string(cname, "$HIB$", HIB);
        cname = replace_string(cname, "$HIM$", HIM);
        cname = replace_string(cname, "$HIC$", HIC);
        cname = replace_string(cname, "$HIW$", HIW);
        cname = replace_string(cname, "$NOR$", NOR);
        cname += NOR;
	switch( ctype ) {
                case "axe":
                        newfile = read_file(__DIR__"obj/weapons/axe.c");
                        break;
                case "blade":
                        newfile = read_file(__DIR__"obj/weapons/blade.c");
                        break;
                case "dagger":
                        newfile = read_file(__DIR__"obj/weapons/dagger.c");
                        break;
                case "fork":
                        newfile = read_file(__DIR__"obj/weapons/fork.c");
                        break;
                case "hammer":
                        newfile = read_file(__DIR__"obj/weapons/hammer.c");
                        break;
                case "staff":
                        newfile = read_file(__DIR__"obj/weapons/staff.c");
                        break;
                case "sword":
                        newfile = read_file(__DIR__"obj/weapons/sword.c");
                        break;
                case "whip":
                        newfile = read_file(__DIR__"obj/weapons/whip.c");
                        break;


		default:
			return notify_fail("���ﲻ������Ҫ�Ķ�����\n");
	}
	newfile = replace_string( newfile, "������", cname);
        newfile = replace_string( newfile, "order", cid);
        newfile = replace_string( newfile, "fengyun", id);
	filename = DATA_DIR+"login/" + id[0..0] + "/" + id + "/" + id +sprintf("%d",time()) + ".c";
	if( !write_file(filename, newfile,1))
		return 0;
	ob = new(filename);
	if(ob->move(me)){
	gold->add_amount(-1);
	me->add("created_item",1);
        me->start_busy(1);
	write("�ϣ�\n");
	return 1;
	}
	return 0;
}
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {
                write("�Բ����������ֱ�����һ����ʮ�������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ����������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ������ֱ��������ġ�\n");
                        return 0;
                }
        }
        return 1;
}

int check_legal_id(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 3) || (strlen(name) > 20 ) ) {
                write("�Բ���Ӣ�����ֱ�����������ʮ�����֡�\n");
                return 0;
        }

	return 1;
}
