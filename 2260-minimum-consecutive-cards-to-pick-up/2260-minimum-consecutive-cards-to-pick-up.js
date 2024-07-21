/**
 * @param {number[]} cards
 * @return {number}
 */
var minimumCardPickup = function(cards) {
    const mp={};
    let len=Number.MAX_SAFE_INTEGER;
    for(let i=0;i<cards.length;i++){
        if(cards[i] in mp){
            if(len>(i-mp[cards[i]]+1)){
                len=i-mp[cards[i]]+1;
            }
            
        }
        mp[cards[i]]=i;
    }
    return len!=Number.MAX_SAFE_INTEGER?len:-1;
};