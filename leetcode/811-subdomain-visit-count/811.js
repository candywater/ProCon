/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
var subdomainVisits = function(cpdomains) {
  let table = new Map();
  for(let cp of cpdomains){
    let tmp = cp.split(" ");
    let num = parseInt(tmp[0]);

    let domains = tmp[1].split(".");
    if(domains.length == 3) domains[1] += "." + domains[2];
    domains[0] += "." + domains[1];

    if(domains.length == 3) setvalue(table, domains[2], num);
    setvalue(table, domains[1], num);
    setvalue(table, domains[0], num);

  }

  var str = [];
  for(let [key, value] of table.entries()){
    str.push([value, key].join(" "));
  }
  return str;
};

var setvalue = function(table, domain, num){
  if(table.has(domain))
    table.set(domain, table.get(domain) + num);
  else table.set(domain, num);
}
