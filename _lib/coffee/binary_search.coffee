
"use strict";

binary_search = (low, high, value, list) ->
  mid = parseInt( (parseInt(high) + parseInt low) / 2 )
  # console.log low + " " + high
  # console.log "mid: " + (parseInt(high) + parseInt low)/2
  if value is list[mid] then return mid;
  if high - low <= 1 then return -1;
  if value < list[mid] 
    return binary_search(low, mid, value, list);
  else if value > list[mid]
    return binary_search(mid+1, high, value, list);
    
