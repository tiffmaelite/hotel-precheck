/* This source code is Copyright (c) Vibrant Media 2001-2013 and forms part of the patented Vibrant Media product "IntelliTXT" (sm). */
$iTXT.js.loader["$iTXT.itxt.Controller"]=true;$iTXT.itxt.Controller_Load=function(){var undefined;var $itxtUtil=$iTXT.core.Util;$iTXT.itxt.Controller=$iTXT.core.Class.create({templateLoadUnSubFunc:null,jsLoadUnSubFunc:null,initialiserLoaded:false,templatesLoaded:false,requiresContextualization:false,skipRecontext:false,limitClientParams:[],timeoutPoints:[],timeoutReached:false,init:function(_options)
{if(this.checkLoadTimeOut("init")){return;}
$iTXT.js.modAdTypes=true;$iTXT.itxt.currentController=this;var tmpDispArr=[];$iTXT.subscribe("$iTXT:tmpl:load",$iTXT.core.Event.bind(this,this.templatesLoad),tmpDispArr);this.templateLoadUnSubFunc=tmpDispArr.pop();$iTXT.core.$(document).itxtSubscribe("$iTXT:controller:livelookup",$iTXT.core.Event.bind(this,this.dropLiveLookup));if(!$iTXT.js.librariesLoaded)
{$iTXT.core.$(document).itxtSubscribe("$iTXT:js:load",$iTXT.core.Event.bind(this,this.librariesLoad),tmpDispArr);this.jsLoadUnSubFunc=tmpDispArr.pop();}
else
{this.librariesLoad();}
if(!window.onunload)
{window.onunload=function(){};}},librariesLoad:function()
{if(this.checkLoadTimeOut("librariesLoad")){return;}
if('function'==typeof this.jsLoadUnSubFunc)
{this.jsLoadUnSubFunc();}
$iTXT.fire("$iTXT:libraries:loaded",this);$iTXT.subscribe("$iTXT:hooks:loaded",$iTXT.core.Event.bind(this,this.hooksLoaded));if(!$iTXT.js.qaol||$iTXT.js.pageLoaded)
{this.kickOff();}
else
{var oldOnload=null;if(window.onload)
{oldOnload=window.onload;}
var t=this;window.onload=function()
{if(null!=oldOnload)
{oldOnload(arguments);}
t.kickOff();};}},checkCssLoad:function()
{var testDiv=$iTXT.js.exclCont();if(!testDiv)
{return;}
var testValue;if(testDiv.currentStyle)
{testValue=testDiv.currentStyle.fontFamily;}
else if(getComputedStyle)
{testValue=document.defaultView.getComputedStyle(testDiv,null).getPropertyValue('font-family');}
if(testValue=='x-iTXT')
{return;}
var scriptUrl=$iTXT.cnst.CSS_DIR+'itxtcss_'+$iTXT.cnst.CSS_VER+'.js',scriptElement=document.createElement('script');scriptElement.type='text/javascript';scriptElement.src=scriptUrl;testDiv.appendChild(scriptElement);},kickOff:function()
{if(this.checkLoadTimeOut("kickOff")){return;}
new $iTXT.metrics.Events();$iTXT.fire("$iTXT:metrics:evt",{n:"ll"});this.dropInitialiser();},checkLoadTimeOut:function(position,sendData)
{if(this.timeoutReached)
{return true;}
var difference=(new Date()).getTime()-$iTXT.js.startTime;var methodIds={init:1,librariesLoad:2,kickOff:3,dropInitialiser:4,initialiserLoad:5,dropContextualizer:6,contextualizerLoad:7,dropAdvertiser:8,advertiserLoad:9,templatesLoad:10};if($iTXT.js.timeout.time>-1&&difference>$iTXT.js.timeout.time)
{var msg="<span style='color:red;font-weight:bold;'>Script Execution timeout reached. Timeout occured after "+difference+"ms during the stage {"+position+"}</span>";this.timeoutPoints[this.timeoutPoints.length]={id:methodIds[position],val:difference};sendData=true;if($iTXT.js.timeout.abort)
{var opts={metric:"ph",mt:111,mv:"JAVASCRIPT_TIMEOUT_REACHED",mv2:131,ipid:$iTXT.js.ipid};this._makeLogCall(opts);this.timeoutReached=true;}}
else
{this.timeoutPoints[this.timeoutPoints.length]={id:methodIds[position],val:difference};}
if($iTXT.js.timeout.monitoring&&sendData)
{var mvTimes="";for(var p in this.timeoutPoints)
{mvTimes+=this.timeoutPoints[p].id+":"+this.timeoutPoints[p].val+",";}
mvTimes=mvTimes.substring(0,mvTimes.length-1);var mvPosition=this.timeoutReached?methodIds[position]:0;var opts={mt:123,mv:mvTimes,mv2:mvPosition,ipid:$iTXT.js.ipid};this._makeLogCall(opts);}
return this.timeoutReached;},_makeLogCall:function(opts)
{var url=$iTXT.js.serverUrl+'/al.asp?ts='+(new Date()).getTime();for(var pn in opts)
{url+="&"+pn+"="+encodeURIComponent(opts[pn]);}
$iTXT.core.Util.dropScript(url,function(removeFunction){removeFunction();});},dropInitialiser:function()
{if(this.checkLoadTimeOut("dropInitialiser")){return;}
if($iTXT.js.serverUrl&&$iTXT.cnst.CONTROLLER_INITIALISER)
{var initialiserUrl=$iTXT.js.serverUrl+$iTXT.cnst.CONTROLLER_INITIALISER+"?ts="+$itxtUtil.ts();$iTXT.data.Dom.detectSearchEngines();initialiserUrl+=this._buildSearchEngineParams();if(undefined==this.contentLength)
{this.contentLength=0;try
{this.contentLength=$itxtUtil.convertSpaces($itxtUtil.cleanString($itxtUtil.getInnerText(document.body,$iTXT.js.domTO))).length;}
catch(e)
{this.contentLength=-1;}}
initialiserUrl+="&pagecl="+this.contentLength;var encoding=$itxtUtil.getContentEncoding();if(encoding&&''!=encoding)
{initialiserUrl+="&enc="+encoding;}
initialiserUrl+="&fv="+$iTXT.core.Flash.version.major;initialiserUrl+="&muid=";if(this.limitClientParams&&this.limitClientParams.length>0)
{initialiserUrl+="&lcp="+encodeURIComponent(this.limitClientParams.join(','));}
if(!$iTXT.js.pageRef)
{var refurl=($iTXT.glob&&$iTXT.glob.params)?$iTXT.glob.params.get('refurl',document.location.href):document.location.href;initialiserUrl+="&refurl="+encodeURIComponent(refurl);}
initialiserUrl+="&"+$iTXT.js.pageQuery;$iTXT.fire("$iTXT:initialiser:drop",this);$itxtUtil.dropScript(initialiserUrl,$iTXT.core.Event.bind(this,this.initialiserLoad));}},initialiserLoad:function(cbr)
{if(this.checkLoadTimeOut("initialiserLoad")){return;}
$iTXT.fire("$iTXT:initialiser:loaded",this);$iTXT.glob.newTooltipChrome=1;if(cbr)
{new $iTXT.data.Channel();$iTXT.data.Country.init($iTXT.glob.params.get("cc","en"));$iTXT.js.requiresContextualization=cbr.requiresContextualization;$iTXT.js.chunkKey=cbr.chunkKey;$iTXT.js.requiresAdverts=cbr.requiresAdverts;var isDraggable=$iTXT.glob.params.getBool("drag",1);var useMobile=$iTXT.core.Browser.isTargetedSmartphone($iTXT.glob.params.getBool("tt.force.mobile",false));if(undefined==$iTXT.ui.tt)
{if(useMobile&&$iTXT.glob.params.getBool('js.mobile.chrome',false))
{$iTXT.ui.tt=new $iTXT.ui_mobile.Tooltip({draggable:isDraggable});}
else
{$iTXT.ui.tt=new $iTXT.ui.Tooltip({draggable:isDraggable});}
this.ttHolder=$iTXT.core.Builder.make("DIV",{id:"itxtttholder",style:"z-index: 9900000; position: absolute; top: 0; left:0;"},[$iTXT.ui.tt.rootElement]);document.body.appendChild(this.ttHolder);$iTXT.ui.tt.build();}
$iTXT.data.PixelController.init();$iTXT.glob.params.set("server",$iTXT.data.al.server,$iTXT.cnst.WEIGHTING_CHANNEL_DEFAULT);var ldr=$iTXT.glob.params.get("ldr","0");if("1"==ldr&&''!=document.referrer)
{var mtOpts={mt:56,mv:document.referrer,advert:{params:$iTXT.glob.params}};$iTXT.fire("$iTXT:data:log:monitor",mtOpts);}
this.initialiserLoaded=true;$iTXT.fire("$iTXT:metrics:evt",{n:"intl"});$iTXT.glob.params.set("so",$iTXT.cnst.Source.ITXT,$iTXT.cnst.WEIGHTING_CAMPAIGN_DEFAULT);if(!this.skipRecontext)
{$iTXT.js.pageContextualized=1;if(!!window.Worker)
{$iTXT.data.Context.getContent();}
else
{$iTXT.data.Context.getContent();}
if($iTXT.glob.params.get('context.timeout.log',-1)>0&&$iTXT.data.Context.timedOut)
{var mtOpts={mt:116,mv:$iTXT.data.Context.lastTimeOut,mv2:$iTXT.data.Context.getProcessedPercentage(),advert:{params:$iTXT.glob.params}};$iTXT.fire("$iTXT:data:log:monitor",mtOpts);}
if($iTXT.js.requiresContextualization)
{if($iTXT.data.Context.timedOut)
{this.dropAdvertiser();}else{this.dropContextualizer();}}
else
{if($iTXT.js.requiresAdverts)
{this.advertiserLoad();}}}}
this.checkCssLoad();},dropContextualizer:function()
{if(this.checkLoadTimeOut("dropContextualizer")){return;}
if($iTXT.js.serverUrl&&$iTXT.cnst.CONTROLLER_CONTEXTUALIZER)
{this.getRelatedContentDetails();$iTXT.fire("$iTXT:metrics:evt",{n:"contint",t:'interval'});var tree=$iTXT.data.Context.tree;if($iTXT.data.Context.treeObjectMode)
{tree=$itxtUtil.serialiseJSON(tree,$iTXT.data.Context.allowedFields);}
var opts={contextUrl:this._createContextUrl(tree),chunkUrl:this._createChunkUrl(),callback:$iTXT.core.Event.bind(this,this.contextualizerLoad),data:tree};$iTXT.fire("$iTXT:contextualizer:drop",this);$iTXT.core.Ajax.postData(opts);}},_createContextUrl:function(tree)
{var contextUrl=$iTXT.js.serverUrl+$iTXT.cnst.CONTROLLER_CONTEXTUALIZER+"?ts="+$itxtUtil.ts();contextUrl+=this._buildSearchEngineParams();var extraPrms=["dfr","rc.a.d","rc.a.t","rc.a.st"];contextUrl+=this._buildQueryParams($iTXT.glob.params,extraPrms);contextUrl+="&pagecl="+this.contentLength;contextUrl+='&jsoncl='+tree.length;contextUrl+='&ppc='+$iTXT.data.Context.getProcessedPercentage();contextUrl+="&hn="+$iTXT.data.Context.textNodes.length;if($iTXT.data.Context.pageTitle){contextUrl+="&ttxt="+encodeURIComponent($iTXT.data.Context.pageTitle);}
return contextUrl;},_createChunkUrl:function()
{return $iTXT.js.serverUrl+$iTXT.cnst.CONTROLLER_CHUNK;},contextualizerLoad:function()
{if(this.checkLoadTimeOut("contextualizerLoad")){return;}
$iTXT.fire("$iTXT:contextualizer:loaded",this);$iTXT.fire("$iTXT:metrics:evt",{n:"contint"});$iTXT.fire("$iTXT:metrics:evt",{n:"contl"});if($iTXT.js.requiresAdverts)
{this.dropAdvertiser();}},dropAdvertiser:function()
{if(this.checkLoadTimeOut("dropAdvertiser")){return;}
if($iTXT.js.serverUrl&&$iTXT.cnst.CONTROLLER_ADVERTISER)
{$iTXT.fire("$iTXT:metrics:evt",{n:"advint",t:'interval'});var advertiserUrl=$iTXT.js.serverUrl+$iTXT.cnst.CONTROLLER_ADVERTISER+"?ts="+$itxtUtil.ts();var extraPrms=["ign86"];advertiserUrl+=this._buildQueryParams($iTXT.glob.params,extraPrms);$iTXT.fire("$iTXT:advertiser:drop",this);$itxtUtil.dropScript(advertiserUrl,$iTXT.core.Event.bind(this,this.advertiserLoad));}},advertiserLoad:function()
{if(this.checkLoadTimeOut("advertiserLoad")){return;}
$iTXT.fire("$iTXT:advertiser:loaded",this);$iTXT.fire("$iTXT:metrics:evt",{n:"advint"});$iTXT.fire("$iTXT:metrics:evt",{n:"advl"});$iTXT.tmpl.check();},templatesLoad:function()
{if(this.checkLoadTimeOut("templatesLoad",true)){return;}
this.templatesLoaded=true;if('function'==typeof this.templateLoadUnSubFunc)
{this.templateLoadUnSubFunc();}
$iTXT.fire("$iTXT:metrics:evt",{n:"tl"});$iTXT.ui.HookManager.execute();},_buildQueryParams:function(pms,extraKeys)
{var retStr="";var cnst=$iTXT.cnst.Params;var keys=[cnst.REF,cnst.REF_MD5,cnst.UID,cnst.UID_MD5,"ipid","cc","rcc","reg","dma","city","auat","fo",["did","a.did"],["syid","a.syid"],["pid","a.pid"],"eat","dat","sest","seid","sehs","test","ugoogle"];extraKeys=extraKeys||[];keys=keys.concat(extraKeys);retStr+="&"+$itxtUtil.generateQueryString(keys,pms);return retStr;},_buildSearchEngineParams:function()
{var rs="";if($iTXT.js.SearchEngineSettings.current)
{rs+="&sest="+$iTXT.js.SearchEngineSettings.current.sest;rs+="&seid="+$iTXT.js.SearchEngineSettings.current.seid;rs+="&sehs="+$iTXT.js.SearchEngineSettings.current.sehs;}
return rs;},getRelatedContentDetails:function()
{var tObj=$iTXT.glob.params.get("iet",'<title>');var tObjIdx=$iTXT.glob.params.get("ieto",1);var sObj=$iTXT.glob.params.get("ies");var sObjIdx=$iTXT.glob.params.get("ieso",1);var dObj=$iTXT.glob.params.get("ied");var dObjIdx=$iTXT.glob.params.get("iedo",1);var title=undefined;var subtitle=undefined;var date=undefined;if(dObj)
{var dateTag=$iTXT.data.Dom.getElementByTagName(dObj,dObjIdx-1);if(dateTag)
{date=$itxtUtil.getText(dateTag);}
else
{dateTag=$iTXT.data.Dom.getElementByClassName(dObj,dObjIdx-1);if(dateTag)
{date=$itxtUtil.getText(dateTag);}}}
if(tObj)
{var titleTag=$iTXT.data.Dom.getNodeByTagClassOrId(tObj,tObjIdx-1);if(titleTag)
{title=$itxtUtil.getText(titleTag);}}
if(sObj)
{var sTitleTag=$iTXT.data.Dom.getNodeByTagClassOrId(sObj,sObjIdx-1);if(sTitleTag)
{subtitle=$itxtUtil.getText(sTitleTag);}}
var w=$iTXT.cnst.WEIGHTING_DEFAULT_CHANNEL;$iTXT.glob.params.set("rc.a.d",date,w);$iTXT.glob.params.set("rc.a.t",title,w);$iTXT.glob.params.set("rc.a.st",subtitle,w);},dropTimeoutID:-1,scriptDropped:false,hooksLoaded:function(e)
{var hks=e.data||[];if(hks.length>0)
{$iTXT.subscribe("$iTXT:ad:view",$iTXT.core.Event.bind(this,this.adView));var t=this;this.dropTimeoutID=setTimeout(function(){t.dropSS();},7000);}
else
{this.dropSS();}},adView:function(e)
{if(!this.scriptDropped)
{var ad=e.data||null;if(ad)
{if(-1!=this.dropTimeoutID)
{clearTimeout(this.dropTimeoutID);}
var script=ad.params.get("scriptsrc");if(script)
{if(ad.params.containsTokens(script)){script=ad.params.parse(script);}
this.dropSS(unescape(script));}}}},dropSS:function(s)
{s=s||$iTXT.glob.params.get("scriptsrc");if('string'==typeof s&&s.indexOf("http:"!=-1))
{$itxtUtil.dropScript(s);this.scriptDropped=true;}}});if(undefined==$iTXT.itxt.currentController)
{new $iTXT.itxt.Controller();}};