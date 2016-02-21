
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// channeld.c

#include <ansi.h>
#include <net/dns.h>
inherit F_DBASE;
mapping channels = ([
        "sys":  ([      "msg_speak": HIB "��ϵͳ��%s��%s\n" NOR, "wiz_only": 1 ]),
	"qst" : ([      "msg_speak": BLU "������%s��%s\n" NOR, "anonymous": " ", "wiz_only": 1 ]),
        "wiz":  ([      "msg_speak": HIY "����ʦ��%s��%s\n" NOR, "wiz_only": 1 ]),
        "gwiz": ([      "msg_speak": HIG "��������ʦ��%s��%s\n" NOR,
                                "msg_emote": HIG "��������ʦ��%s %s.\n" NOR,
                                "wiz_only": 1, "intermud": GWIZ, "channel":
"CREATOR",
                                "filter": 1 ]),
        "gchat": ([      "msg_speak": HIG "���������ġ�%s��%s\n" NOR,
                                "msg_emote": HIG "���������ġ�%s %s.\n" NOR,
                                "wiz_only": 1, "intermud": GCHANNEL, "channel":
"chat",
                                "filter": (: $1["MUDLIB"]!="":)]),
        "chat": ([      "msg_speak": HIC "�����ġ�%s��%s\n" NOR ]),
        "fy":   ([      "msg_speak": HIR "�����ơ�%s��%s\n" NOR,
			"msg_emote": HIR "�����ơ�%s\n" NOR,
                                "intermud": GCHANNEL, "channel": "fy",
				"filter": (: $1["MUDLIB"]!="" :) ]),
        "es":   ([      "msg_speak": HIR "���������¡�%s��%s\n" NOR,
                                "msg_emote": HIG "���������¡�%s.\n" NOR,
                                "intermud" : GCHANNEL, "channel": "es",
                                "filter" : (: $1["MUDLIB"]!="":) ]),
        "at":   ([      "msg_speak": HIM "������ҥ�ԡ�%s��%s\n" NOR,"anonymous":"ĳ��",
                                "intermud" : GCHANNEL, "channel": "rumor",
                                "filter" : (: $1["NAME"]="sd":) ]), 
 	"rumor":(["msg_speak": HIM "��ҥ�ԡ�%s��%s\n" NOR,"anonymous": "ĳ��"]), 
	]);

int block_rumor = 0;
int block_chat = 0;

void create()
{
        seteuid(getuid()); // This is required to pass intermud access check.
        set("channel_id", "Ƶ������");
}

varargs int do_channel(object me, string verb, string arg, int emote)
{
        object *ob;
        string *tuned_ch, who;
        if ((int)me->query("chblk_on") && !wizardp(me))
             return notify_fail("���Ƶ�����ر��ˣ�\n");
        if ((int)me->query("chblk_on") && wizardp(me))
        {
        //only block a wiz's rumor and chat...
                me->set("chblk_rumor", 1);
                me->set("chblk_chat", 1);
        }
        if ((int)me->query("chblk_rumor") && (verb == "rumor"||verb == "rumor*") )
                return notify_fail("���ҥ��Ƶ�����ر��ˣ�\n");
        if ((int)me->query("chblk_chat") && (verb == "chat"||verb == "chat*") )
                return notify_fail("�������Ƶ�����ر��ˣ�\n");
        // check if rumor or chat is blocked
        if ((int)block_rumor && (verb == "rumor"||verb == "rumor*") )
                return notify_fail("ң��Ƶ�����ر��ˣ�\n");
        if ((int)block_chat && (verb == "chat"||verb == "chat*") )
                return notify_fail("����Ƶ�����ر��ˣ�\n");

        if( !mapp(channels) || undefinedp(channels[verb]) )
                return 0;
        if( userp(me) ) {
                if(channels[verb]["wiz_only"] && !wizardp(me) )
                        return 0;

                if( arg==(string)me->query_temp("last_channel_msg") )
                        return 
notify_fail("�ý�̸Ƶ��˵���벻Ҫ�ظ���ͬ��ѶϢ��\n");

         // If we speaks something in this channel, then must tune it in.
                tuned_ch = me->query("channels");
                if( !pointerp(tuned_ch) )
                        me->set("channels", ({ verb }) );
                else if( member_array(verb, tuned_ch)==-1 )
                        me->set("channels", tuned_ch + ({ verb }) );
        }
        if( channels[verb]["anonymous"] ) {
                who = channels[verb]["anonymous"];
                if (verb == "rumor") {
                  if (userp(me))
                  do_channel( this_object(), "sys", sprintf("ҥ�ԣ�%s��", me->name()));
                }
        }
        else if( userp(me) || !stringp(who = me->query("channel_id")) )
                who = me->query("name") + "(" + capitalize(me->query("id")) + ")";

        // Ok, now send the message to those people listening us.
ob = filter_array(users(),"filter_listener",this_object(),channels[verb]);
           if( !arg ) arg = "...";
	if( emote )
        message( "channel:" + verb,
                sprintf( channels[verb]["msg_emote"],arg ),ob);
	else
        message( "channel:" + verb,
                sprintf( channels[verb]["msg_speak"], who, arg ), ob );

        if( arrayp(channels[verb]["extra_listener"]) ) {
                channels[verb]["extra_listener"] -= ({ 0 });
                if( sizeof(channels[verb]["extra_listener"]) )
           channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
        }
        
        if( !undefinedp(channels[verb]["intermud"])
        &&      base_name(me) != channels[verb]["intermud"] )
                channels[verb]["intermud"]->send_msg(
     channels[verb]["channel"], me->query("id"), me->name(1), arg, emote,
                        channels[verb]["filter"] );

        if( userp(me) ) 
                me->set_temp("last_channel_msg", arg);

        return 1;
}

int filter_listener(object ppl, mapping ch)
{
        // Don't bother those in the login limbo.
        if( !environment(ppl) ) return 0;
        
        if( ch["wiz_only"] ) return wizardp(ppl);
        return 1;
}

void register_relay_channel(string channel)
{
        object ob;

        ob = previous_object();
        if( undefinedp(channels[channel]) || !ob) return;
        if( arrayp(channels[channel]["extra_listener"]) ) {
                if( member_array(ob, channels[channel]["extra_listener"]) >=0 
) return;
                channels[channel]["extra_listener"] += ({ ob });
        } else
                channels[channel]["extra_listener"] = ({ ob });
}
 
int set_block(string channel, int d)
{
        if (channel == "rumor") block_rumor = d;
        if (channel == "chat") block_chat = d;
        return 1;
}

