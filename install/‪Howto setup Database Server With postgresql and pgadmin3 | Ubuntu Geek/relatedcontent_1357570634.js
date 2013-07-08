/* This source code is Copyright (c) Vibrant Media 2001-2013 and forms part of the patented Vibrant Media product "IntelliTXT" (sm). */
if(!$iTXT){var $iTXT={};};if(!$iTXT.tmpl){$iTXT.tmpl={};};if(!$iTXT.tmpl.js){$iTXT.tmpl.js={};};$iTXT.tmpl.dependsOn("RelatedContentList",true);$iTXT.tmpl.dependsOn("SearchBar",true);$iTXT.tmpl.loader["$iTXT.tmpl.js.RelatedContent"]=true;$iTXT.tmpl.js.RelatedContent_Load=function()
{$iTXT.tmpl.components.RelatedContentList_Load();$iTXT.tmpl.components.SearchBar_Load();$iTXT.tmpl.js.RelatedContent=$iTXT.core.Class.create($iTXT.tmpl.TemplateBase,{afterTokenize:function()
{var adps=this.advert.params;var adhtml=adps.get("iefh","");var soa=adps.getBool("iesoa",false);if(soa)
{this.removeElement("AdvertCell");this.removeElement("AdvertPaddingCell");}
else if(""==adhtml)
{this.removeElement("AdvertCell");this.removeElement("AdvertPaddingCell");}
else
{adps.set("rc.ad.html",adhtml,$iTXT.cnst.WEIGHTING_DEFAULT_CAMPAIGN);var rcw=adps.getInt("rc.width",450);adps.set("width",rcw+310,$iTXT.cnst.WEIGHTING_DEFAULT_CAMPAIGN);}
var iessu=this.advert.params.get("iessu","");if(""==iessu)
{this.removeElement("BottomSearchBar");this.removeElement("TopSearchBar");adps.set("rc.list.showmore","0",$iTXT.cnst.WEIGHTING_DEFAULT_TEMPLATE);}
else
{var searchBarPos=adps.parse("${rc.sb.state}");if("1"==searchBarPos)
{this.removeElement("BottomSearchBar");adps.set("rc.list.showmore","1",$iTXT.cnst.WEIGHTING_DEFAULT_TEMPLATE);}
else if("2"==searchBarPos)
{this.removeElement("TopSearchBar");$iTXT.core.$(document).itxtFire("$iTXT:tt:ftr:set:bgcol",adps.get("rc.ftr.sbb.col"));$iTXT.core.$(document).itxtFire("$iTXT:tt:ftr:set:hvcol",adps.get("rc.ftr.sbb.col"));$iTXT.core.$(document).itxtFire("$iTXT:tt:tail:set:bgcol",adps.get("rc.tail.sbb.col"));$iTXT.core.$(document).itxtFire("$iTXT:tt:tail:set:hvcol",adps.get("rc.tail.sbb.col"));adps.set("rc.list.showmore","0",$iTXT.cnst.WEIGHTING_DEFAULT_TEMPLATE);}
else
{this.removeElement("BottomSearchBar");this.removeElement("TopSearchBar");adps.set("rc.list.showmore","0",$iTXT.cnst.WEIGHTING_DEFAULT_TEMPLATE);}}
var rcLogo=adps.get("rctu","");var newRcLogo=adps.get("rc.sb.logo","");if(""!=rcLogo&&""==newRcLogo)
{var lindx=rcLogo.lastIndexOf("/");if(-1!=lindx&&rcLogo.length>4)
{adps.set("rc.sb.logo","${rc.img.dir}/logos_v4/"+rcLogo.substring(lindx,rcLogo.length-4)+".png",$iTXT.cnst.WEIGHTING_DEFAULT_TEMPLATE);}}
if(""!=rcLogo||""!=newRcLogo)
{$iTXT.core.Util.cacheImage(adps.parse("${rc.sb.logo}"));}
var articles=adps.get("rc.articles",[]);var sLen=80;var maxRows=parseInt(adps.parse("${rc.list.max.articles}"));var noAds=articles.length;if(1==noAds)
{sLen=255;}
else if(2==noAds)
{sLen=130;}
else if(noAds<maxRows)
{sLen=110;}
adps.set("rc.list.body.len",sLen,$iTXT.cnst.WEIGHTING_DEFAULT_TEMPLATE);if(articles.length>0)
{var firstAd=articles[0];var url=firstAd.url;if(url)
{adps.set("CLICKTAG",url,$iTXT.cnst.WEIGHTING_DEFAULT_CAMPAIGN);}}},onBuildHookStyle:function(hkDefOpts)
{var adps=this.advert.params;var hks=adps.get("rc.hk.style");if(null!=hks&&""!=hks&&"${rc.hk.def.style}"!=hks)
{var hkhs=adps.get("rc.hk.h.style");if(hkhs==null||""==hkhs||"${rc.hk.def.h.style}"==hkhs)
{adps.set("rc.hk.h.style","${rc.hk.style};background-color:${rc.hk.bg.h.col};",$iTXT.cnst.WEIGHTING_DEFAULT_CAMPAIGN);}}
hkDefOpts.hookActiveStyle="${rc.hk.h.style}";hkDefOpts.hookStyle="${rc.hk.style}";},searchClick:function(kw,so)
{if(!kw||""==kw)
{kw=this.advert.$A.kw;}
var redir=this.advert.params.get("iessu",null);if(null!=redir)
{redir=redir.replace("_SEARCHKEYWORD_",encodeURIComponent(kw));var opts={redir:redir,advert:this.advert,so:so||13};var feat=this.advert.params.get("rc.featured",null);if(null!=feat)
{opts.di=this.advert.$A.did;opts.pid=8;}
$iTXT.core.$(document).itxtFire("$iTXT:tt:click",opts);}},onLogEvent:function(type,qp,a,o)
{if($iTXT.data.LogEventType.HOOKCLICK==type)
{var feat=this.advert.params.get("rc.featured",null);if(null!=feat)
{qp.di=feat.did;qp.wch=feat.mdh;qp.ldid=this.advert.$A.did;qp.redir=feat.url;o.cts=false;}}
else if($iTXT.data.LogEventType.ADVIEW==type)
{var feat=this.advert.params.get("rc.featured",null);if(null!=feat)
{qp.wch=feat.mdh;qp.ldid=feat.did;}}
return true;},featuredClick:function(i,ct,did,mdh)
{var opts={advert:this.advert,so:$iTXT.cnst.Source.IEB+i,redir:ct,di:did,wch:mdh,ldid:this.advert.$A.did,cts:false};$iTXT.core.$(document).itxtFire("$iTXT:tt:click",opts);},itemClick:function(i,ct)
{var opts={advert:this.advert,so:$iTXT.cnst.Source.IEB+i,redir:ct};$iTXT.core.$(document).itxtFire("$iTXT:tt:click",opts);},init:function(_options,$super)
{if(_options.advert)
{var p=_options.advert.params;var atig0=p.get("atig0");var w=$iTXT.cnst.WEIGHTING_DEFAULT_CAMPAIGN;if("none"==atig0)
{p.set("hk.icon","",w);p.set("hk.icon.active","",w);}
else if(""!=atig0)
{p.set("hk.icon",atig0,w);p.set("hk.icon.active",atig0,w);}}
this.paramDefaults=$iTXT.core.Util.extend({'iert':'${iera}','hdr.txt':'${iert}','rc.img.dir':'http://images.intellitxt.com/ast/related_content/','rc.sb.logo':'','rc.sb.bg':'${rc.img.dir}assets/sb_bg.png','rc.sb.ipbg':'${rc.img.dir}assets/ip_bg.png','rc.sb.iplbg':'${rc.img.dir}assets/ip_lbg.png','rc.sb.btnbg':'${rc.img.dir}assets/btn_search.png','ielc':'#CE621F','rcsrchbtnclr':'${ielc}','rc.sb.btn.col':'${rcsrchbtnclr}','hk.icon':'mag-glass_10x10.gif','hk.icon.active':'mag-glass_10x10.gif','rc.hk.def.style':'text-decoration: none; border-bottom: 1px dotted ${rc.hk.fg.col}; border-top: none; color: ${rc.hk.fg.col}; background-color: ${rc.hk.bg.col}','rc.hk.def.h.style':'text-decoration: none; border-bottom: 0.2em solid ${rc.hk.fg.h.col}; border-top: none; color: ${rc.hk.fg.h.col}; background-color: ${rc.hk.bg.h.col}','rc.hk.style':'${rc.hk.def.style}','rc.hk.h.style':'${rc.hk.def.h.style}','rc.hk.fg.col':'#95181C','rc.hk.fg.h.col':'#0099FF','rc.hk.bg.col':'transparent','rc.hk.bg.h.col':'transparent','rc.ftr.sbb.col':'#d6d6d6$$#d6d6d6$$#d5d4d4$$#d1d1d2$$#cecece$$#cbcbcb','rc.tail.sbb.col':'#c7c7c7$$#c3c3c3$$#c1c1c1$$#bfbebf$$#bdbdbd$$#bbbbbc$$#bababb$$#b9b9b8$$#b7b7b7$$#b6b5b5$$#b5b5b4$$#b3b3b3$$#b2b2b2$$#b0b1b0$$#afafaf$$#aeaeae','rc.list.more':'1','rc.list.bg.col':'white','rc.list.title.col':'${ielc}','rc.list.body.col':'#333333','rc.list.url.col':'#008000','rc.list.shad.top':'${rc.img.dir}assets/shadow_t.png','rc.list.shad.bottom':'${rc.img.dir}assets/shadow_b.png','rc.list.border.top':'1px solid #A0A0A0','rc.list.ad.bg.col':'#FFFFAA','iel':3,'rc.list.max.articles':'${iel}','rc.hldr.border.bottom':'1px solid #A0A0A0','rc.hldr.more.bg':'${rc.img.dir}assets/tab_moreresults.png','rc.hldr.more.col':'${ielc}','rc.ftr.def.col':'#f0f0f0','rc.tail.def.col':'#f0f0f0','tt.ftr.col':'${rc.ftr.def.col}','tt.tail.col':'${rc.tail.def.col}','tt.ftr.h.col':'${rc.ftr.def.col}','tt.tail.h.col':'${rc.tail.def.col}','tt.bg.col':'${rc.ftr.def.col}','rcadbgclr':'#333333','rc.ad.bgc':'${rcadbgclr}','rc.ad.hv.bgc':'${rc.ad.bgc}','rc.item.bgc':'','rc.item.hv.bgc':'','rcsrchbr':'1','rc.sb.state':'${rcsrchbr}','rc.list.title.len':80,'rc.list.url.len':80,'width':450,'height':250,'rc.width':450,'tmpl.soa.enabled':1},this.paramDefaults);var defOpts=$iTXT.core.Util.extend({width:'${width}',height:'${height}',ttbgcol:'white',tthbgcol:'white',ttfooterbgcol:'#F0F0F0',tthoverfooterbgcol:'#F0F0F0',tttailbgcol:'#F0F0F0',tthovertailbgcol:'#F0F0F0'},_options);this.structure=[{type:'row',height:'*',width:'*',structure:[{type:'cell',height:'*',width:450,structure:[{type:'row',UID:'TopSearchBar',height:'**',width:'**',structure:[{type:'cell',height:'**',width:'**',structure:[{type:'comp',height:40,width:'**',klass:'$iTXT.tmpl.components.SearchBar',id:'itxtrctopsb',styles:{},props:{bgimg:'${rc.sb.bg}',ipbg:'${rc.sb.ipbg}',iplbg:'${rc.sb.iplbg}',logo:'${rc.sb.logo}',btnbg:'${rc.sb.btnbg}',btncol:'${rc.sb.btn.col}',btntxt:"${trans.search}",searchtxt:'${a.kw}',ipLeftMargin:-5,searchCallback:$iTXT.core.Event.bind(this,this.searchClick)}}]}]},{type:'row',UID:'ResultsPanel',width:'**',structure:[{type:'cell',width:'**',structure:[{type:'comp',UID:'RCList',height:'*',klass:'$iTXT.tmpl.components.RelatedContentList',id:'itxtrclist',styles:{marginLeft:'5px',marginRight:'5px'},props:{bgCol:'${rc.list.bg.col}',topShadow:'${rc.list.shad.top}',topBorder:'${rc.list.border.top}',holderBottomBorder:'${rc.hldr.border.bottom}',shadowBottom:'${rc.list.shad.bottom}',showMore:'${rc.list.showmore}',showMoreCol:'${rc.hldr.more.col}',showMoreBg:'${rc.hldr.more.bg}',moreResText:'${trans.moreres} &gt;',itemBgCol:'${rc.item.bgc}',itemHvBgCol:'${rc.item.hv.bgc}',featBgCol:'${rc.ad.bgc}',featHvBgCol:'${rc.ad.hv.bgc}',moreResultsCallback:$iTXT.core.Event.bind(this,this.searchClick),titleCol:'${rc.list.title.col}',titleLength:'${rc.list.title.len}',bodyLength:'${rc.list.body.len}',bodyCol:'${rc.list.body.col}',urlLength:'${rc.list.url.len}',urlCol:'${rc.list.url.col}',itemClick:$iTXT.core.Event.bind(this,this.itemClick),featuredClick:$iTXT.core.Event.bind(this,this.featuredClick),maxArticles:'${rc.list.max.articles}'}}]}]},{type:'row',UID:'BottomSearchBar',height:'**',width:'**',structure:[{type:'cell',height:'**',width:'**',structure:[{type:'comp',height:40,width:'**',klass:'$iTXT.tmpl.components.SearchBar',id:'itxtrcbottomsb',styles:{},props:{bgimg:'${rc.sb.bg}',ipbg:'${rc.sb.ipbg}',iplbg:'${rc.sb.iplbg}',logo:'${rc.sb.logo}',btnbg:'${rc.sb.btnbg}',btncol:'${rc.sb.btn.col}',btntxt:"${trans.search}",searchtxt:'${a.kw}',ipLeftMargin:-5,searchCallback:$iTXT.core.Event.bind(this,this.searchClick)}}]}]}]},{type:'cell',UID:'AdvertPaddingCell',height:250,width:5,styles:{backgroundColor:'${tt.ftr.col}'},hoverstyles:{backgroundColor:'${tt.ftr.h.col}'}},{type:'cell',UID:'AdvertCell',height:250,width:300,styles:{backgroundColor:'white'},structure:[{type:'comp',height:250,width:300,klass:'$iTXT.tmpl.Html',id:'itxtrcadvert',props:{src:'${rc.ad.html}'}}]},{type:'cell',UID:'AdvertPaddingCell',height:250,width:5,styles:{backgroundColor:'${tt.ftr.col}'},hoverstyles:{backgroundColor:'${tt.ftr.h.col}'}}]}];$super(defOpts);}});};