
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("老刀把子", ({ "master lao dao", "lao dao"}) );
	set("gender", "男性" );
	set("age", 45);
	set("int", 30);
	set("str", 30);
	set("per", 30);
        set("apprentice_available", 50);
        create_family("幽灵山庄", 1, "庄主");
        set("class", "ghost");
	set("long", "他身穿灰袍，头戴竹笠，就象个有刑无质的鬼魂。\n" );
        set("force_factor", 200);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);
        set("chat_chance", 1);
        set("combat_exp", 9999999);
        set("score", 90000);
        set("skill_public", 1);
        set_skill("foreknowledge", 120);
        set_skill("changelaw", 150);
        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("move", 150);
        set_skill("force", 200);
        set_skill("parry", 150);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("three-sword", 100);
	set_skill("taiji", 100);
	set_skill("taijiforce", 100);
	set_skill("five-steps", 100);

	map_skill("unarmed", "taiji");
        map_skill("sword", "three-sword");
        map_skill("force", "taijiforce");
        map_skill("parry", "three-sword");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");

	setup();
        carry_object(__DIR__"obj/cloth3")->wear();
        carry_object(__DIR__"obj/hat")->wear();
        carry_object(__DIR__"obj/swordd")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本庄主今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
	if((int)ob->query_temp("marks/顾云飞")) {
        	command("stare " + ob->query("id"));
        	command("say 你不是来做奸细的吧？\n");
		return;
        }
        else  if((int)ob->query_temp("marks/幽灵山庄")) {
		say("\n");
        	command("say 好！你把武当的镇山七星宝剑拿来给我，不用拜师，我也传授你一身武功！\n");
		ob->set("marks/拿七星宝剑", 1);
	}
        else {

                command("say 你日后必有大成！");
                command("smile");
                command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "ghost");
        add("apprentice_availavble", -1);
}

int recognize_apprentice(object ob)
{
        if( ob->query("marks/老刀把子") ||(string) ob->query("class") == "ghost")
			return 1;
        return 0;
}

int accept_object(object who, object ob)
{
	if((string)ob->name() != "七星剑") return 0;
	if(!who->query("marks/拿七星宝剑")) return 0;
	if(ob->query("real") && (object)ob->query_temp("marks/owner") == who) {
		who->delete("marks/拿七星宝剑");
		command("spank " + who->query("id"));
                command("say 你想要武功秘集，还是向我学武？(accept book/teach?)");
		who->set_temp("marks/拿到七星宝剑", 1);
		add_action("do_accept", "accept");
	}
	else {
		say("老刀把子接过七星剑，仔细地看了看。\n");
		command("sigh");
                command("say 这一柄又是假的！");
	}
	return 1;
}

int do_accept(string arg)
{
	object		me, book;

	if(!arg || (arg != "book" && arg != "teach")) 
		return notify_fail("什麽？\n");
	me = this_player();
	if(!me->query_temp("marks/拿到七星宝剑"))
		return notify_fail("什麽？\n");
	me->set_temp("marks/拿到七星宝剑", 0);
	if(arg == "book") {
		book = new(__DIR__"obj/book");
		book->move(this_object());
		command("give book to " + me->query("id"));
	}
	else 
		command("say 从今天开始，你可以同我学武了。");
		me->set("marks/老刀把子", 1);
	return 1;
}
void init()
{
        add_action("give_quest", "quest");
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","幽灵山庄弟子");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","幽灵山庄领班");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","幽灵山庄小管家");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","幽灵山庄管家");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","幽灵山庄大管家");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","幽灵山庄总管");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","幽灵山庄大总管");
                return ;
        } else
                student->set("title","幽灵山庄副庄主");
                return ;

}

