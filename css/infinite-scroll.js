/*!
 * hexo-infinite-scroll.js v1.0.3
 * (c) 2018 Frontend Sophie
 * Released under the MIT License.
 */
(function(e){const t=e=>{let t={item:".post",pageSize:3,time:400,loading:{enabled:true,style:"wave",color:"#f78769"}};const i=(e,t)=>{for(let o in t){if(typeof t[o]!=="object"){e[o]=t[o]}else{i(e[o],t[o])}}return e};return i(t,e)};const i=e=>{let t="<span></span>";let i=`<div class="loading">${t.repeat(5)}</div>`;if(e.loading.style==="circle"){i=`<div class="loading">${t.repeat(8)}</div>`}$(e.item).parent().append(i);$(".loading").addClass(e.loading.style);$(".loading span").css("background",e.loading.color)};const o=()=>{if($(".loading")){$(".loading").remove()}};const l=e=>{let l=t(e);$(document).ready(()=>{let e=1;const t=l.pageSize;const n=$(l.item).length;if(n>1){$(l.item).hide();$(l.item).slice(0,t).show();$(l.item).parent().css("position","relative");let s=false;const a=()=>{let a=$(document).scrollTop()>=$(document).height()-$(window).height();let d=e*t;let c=d>=n;if(a&&!c&&!s){s=true;if(l.loading.enabled){i(l)}const n=()=>{e++;$(l.item).slice(0,e*t).show();s=false;o()};setTimeout(n,l.time)}};$(window).scroll(a)}})};e.infiniteScroll=l})(window);
