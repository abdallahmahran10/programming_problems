

#include "common.h" // my defined macros

std::string::size_type matchingCharactersCount(std::string s1, std::string s2) {
  sort(begin(s1), end(s1));
  sort(begin(s2), end(s2));
  std::string intersection;
  std::set_intersection(begin(s1), end(s1), begin(s2), end(s2),
                        back_inserter(intersection));
  return intersection.size();
}

int maxProduct(vector<string>& words) 
{
	int len = words.size();
	if(len < 2)
		return 0;
	
	priority_queue<int> queue;
	queue.push(0);
	for(int i= 0; i<len;i++ )
	{
		for(int j=i +1 ; j<len; j++ )
		{
			if(matchingCharactersCount(words[i],words[j])<1)
				queue.push(words[i].length() * words[j].length());
		}
	}

	return queue.top();
}
// test cases
int testCase0()
{
	/*
		Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
		Return 16
		The two words can be "abcw", "xtfn".
	*/
	vector<string> words;
	words.push_back("abcw");
	words.push_back("baz");
	words.push_back("foo");
	words.push_back("bar");
	words.push_back("xtfn");
	words.push_back("abcdef");
	//
	return maxProduct(words);
}
int testCase1()
{
	/*
		Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
		Return 4
		The two words can be "ab", "cd".
	*/
	vector<string> words;
	words.push_back("a");
	words.push_back("ab");
	words.push_back("abc");
	words.push_back("d");
	words.push_back("cd");
	words.push_back("bcd");
	words.push_back("abcd");
	//
	return maxProduct(words);
}
int testCase2()
{
	/*
		Given ["a", "aa", "aaa", "aaaa"]
		Return 0
		No such pair of words.
	*/
	vector<string> words;
	words.push_back("a");
	words.push_back("aa");
	words.push_back("aaa");
	words.push_back("aaaa");
	//
	return maxProduct(words);
}
//
int testCase3()
{
	string strArr[]  = {"gfgc","bfdcabbbdbfd","acbeaacfecfbdagaebbeagddgb","fdfefbgffegfcc","cagcbgg","eff","fcdabfcaa","gggdcfacfcdeecfdcbfaeadbec","eaccfagbcagafagfebgdc","aaebefcebcfe","ebdcge","aaeecgcacaece","gfgdafecedbgbaccggegbadfcca","bebefebffdfabcfdg","fdcdaggdcaceabgadgbgab","agdcggbcdagbbcbgaeagaggf","caccecbaggfa","ecegegdcaef","ffaadgaedggabaccebggc","acgaeeafffbbebfcdfdgebcbbg","aacdefgfbaedggfe","bbcfgddgeafcfdbadccgade","bddeacgaggfeeageaaagaccdga","ge","gbgbgebefgefddfdfg","adfdeegacaeabafeafeggdbdabe","ggafeacfgeafggfefggb","afggdcacfafbdcgbb","agedabcfb","dgdbfa","cccgcdfedafgbccdbagebe","dgaadebcggbagbafgbaaecd","gg","fggbeeefdcgcfaeacbbadbfgd","abdegggfeacfcacgceadgbfddc","febd","afdabadgeedbcg","ggc","acefcbec","eaeffebcfgeffccafdb","aeedfc","eabcd","cfafcecbdegd","bgegdccdcgebbecegbgg","bdadfdgdceegd","gefecgbacedcafcgeec","bdfbbac","debgcggbggbaeacgaddcbbefcde","fccfe","acfacgaegeg","cdcfecadbfcag","efc","caccdaafegbdaafedbabfebfe","dcbedbaagbccd","gcbgceaefgfbceegf","ab","aee","aaa","gecaccebbbdgd","eeaafgcggedbgcfadcedffgb","abcbbgddfbecceebg","fd","bccgcgagcdd","ccagbdfagdecgdc","fcbfedaagde","cgcebebecfgffgcdgc","cbeedgdgecbfcfdcgbdbcd","cagccdedbffcfabcacegbe","bgfbebdbbecabgagafagcecdabf","bcddffgefeaabbddedgbee","abbfade","agggbebegcegebfe","baaecbgbdaaaged","fad","daccccdfdgedbdgebcaeeecaba","cfeffaegg","bcaac","aadbcbddedbbabf","bdcfegccfgefb","aab","fggagcf","be","eabf","cbg","cbggbededceffddabbfcg","aegdfffdbc","ffggdgga","aeb","gfbdeegadccdbgedcebce","ebcgdbc","aad","fegeeeeaccfbfdgdefgef","fbgaaaddcf","ceebfdegcegdgdcbbddadfe","egdbfabgfafgaeafagb","cbdg","ebceedadcfd","cbbgecfeegbadbea","cgccbfbgaaeceff","ebcffgbfdggfbbgdeeaddbdec","dbcbddgdcegbabbgfgecdbgfe","cddfgcfbabdffaadfgeebdgd","cfcaaafaab","cegdaafcffbfedgaeeedbecb","fdaeggagcaecadadaacgfdg","fafagffbegcedededaaeaf","bbdabacabcfgage","edeaddebgagacdagecebebge","eeecfg","eefbcefdcabadecgfcfdfgefa","dgccagdaed","bbegfdfeacaddgacddbbfgcfde","bdc","affgecdbgeebffdfadg","adcafc","cbagc","cbbffebea","agfa","efbcffegabfeggdegdd","eededbdegdefeebfebbaf","agacdagfebdadaddedcddg","bafadccdfdbcfbbdgagafg","ebaefgfg","ecgbacffdfgdagae","gfedefgecbcffagbagbeeefaeab","dabebafabcfebbebbda","agdgedccdccdgcbgdcebfbaccf","fagacdccbgagabebac","efaeb","bbfadbbgdcgbefdfbeededabd","gc","ddebgedfgcfeedgdbagebfceafe","gadeabb","cecgeagddcdf","gbccdgccccgbdcbebabebfba","deegcee","fcedcabeg","gdfdgebggcadaeafcddbeegfc","agcfdbdg","bbafdbdccdcfgfe","fcbcdee","ebeddcagadccbadd","afadebbefcddgdg","acfdeedcgdcecfagacdacg","bcdbcgegegdgcdcgcfcggafda","acdcfaacedegebccc","addabdcgegdcdbbaeabfggg","fcedefdeeaeaeab","befdggaff","eafggc","dcdccadcdfebca","eedecdbcgfeabggbge","edccadbgeggb","bbagdcfbaac","fegfddaeedfd","abdgeaefbefdfdgb","eadegdd","cdcffaadfcaedeeegacc","bafaebcgaca","feeggdbgfeecgfefabccg","fegaddf","bfgffgffdffcffagbdc","bgcbcdbdgcfga","ddegbbfa","ddedccefecdgfdaccdadfffbaeb","cfgbfaaabbbbgaeabadccdeeff","fddgdbeabfggafdgcbede","gggfffgdgdgdfdcaefegd","fdc","fffcgfeadadgefcgaefccff","gggebebfgggfeeafbbdefb","afedacbeffefcfddbfdaefdfd","bbdffgacfgaebcab","bcfeggaecbeafcddgbbgce","dfgffbeegbba","gadbf","egcbgedgda","fbfbefce","cfdcacfcdgbaagag","egaae","edbabfcfcddgfffbggecfdbfcfg","ef","bfagffb","adgcdbaafagd","dfgeeddggaebabececbbeba","aabccfgggafgbebac","acgc","dcfbdbgfg","fcbgacfbde","fabdadadgfc","dggfegee","dgggaefeddaeafggaa","geegfabeeadddgbgegagdcecbad","ffbeacbegecegdaadcc","facbfdeeafddececf","fddfebfd","efb","egebdfggdccdecdcdagfgacdcc","eeebbdbefcdfacdbc","aaedbedfaegadfagec","agcddbab","ffabffgdgcdbeeacgagfae","ggfea","begdg","ceddafddgb","bafgbddabefbgedagadgeadg","gbcfbgf","gagfggdbfccc","cffag","cccegcfagdeefggbdcf","adcdgac","ffbg","ccgcedecceb","adegacd","egbbgfacg","cabece","bcaeaecddbefbdf","edbedbag","eaffdgfgcdbdfdccagaad","fdfgebddgbebgbbbdffge","eadaccgbaf","aedfeccdffeffabgdfbea","bdceebcgaccedbdabffdffbfag","fdgfegeeabeegbcaebdf","cdebccda","ddabfdfbefbeaecbcabcdbd","fdedeeadcbedfdbdfgcf","cfgabaefcbdfcbfdbbcafdcdeb","fecccacgcecgcbbadabbcace","caadeeadbfgebdbaa","bcbgbffcbbbfbf","bfgdfeac","fceccaagaa","bagbcfefbeddgec","cdfbbbbadeacacbgaffccfbegg","adcageadebeecgdeefegfaaadde","daabfggdeafebeaad","addaefbefbdfgegdbcffgdedefe","ddadbbcccfbacaceffde","bggeagfedg","bfgabcbbcdbgdgg","cefeagbcfae","ceafefb","gcbdegfaeaegbc","dcgcefdcgfggeefbeacebfg","ccdfce","faccebdgcbegeedccfeececbc","efabeaacfddacadfgfcgd","addfaeaaafffd","agc","edfdgcabecffacefdcecfbfegc","ddaeaeaeccedgbccfefbee","ag","cedfcacaagadfcgddcgb","dfagcceccgdbbcdc","gbceee","edfdaabeedbfea","cgbcaeaebafcbccbcdbecgcdbg","ffadceefbfeccebf","gf","edacdffff","egbf","fefgfeecfgfdag","afeaaebcbcacgcgdde","cgffbafeggggdbeebabg","bbgggfadbecegdaafcg","db","bddgaaaacbfgagfd","becfaabeedcgg","bagggagfdcggdgfbfc","fbafcefbefbcaeceabdegdef","gfccggfgefd","cfdebac","dfbcfecdgfgfbggdggaabcee","acddabagddggaeefdbbcfebbfd","gabcceafdcaeefbae","fegcecgeggbdgcbcdg","baffcegadcfaffbfcbedaecaf","dbdaedcgcgbcgcacafabgca","dgbeccbbbcdegffe","eeadefede","cedbgfgeabcgagebe","ffdceegagcffdgdbcfbffdgcg","gcdbddgcd","ccddagaafaabebaabg","dedfgdefecfgggbbcececdg","fdbfadd","dgbdgdg","aefgbcbed","daaaebcfefddfcfffadbgab","egeefeaeddbgfaag","cbaaaagceeddefeecbbcgeagcdf","gggddccfaca","cefgedgdcdgaadabcabfac","faceedgecbcd","ecebb","gagfddfggcefgdgggfe","gc","bcbdacdeacdbcd","gddcabaececbdbbeaadfagf","abddceebgfga","edgcgcfggafbbcgfcadfaaddc","cggbcccfbab","fbcgggf","aacceefbdcfdfebeb","dabaebfbfgcddc","faedc","gfgaede","decfccbgbgdcbffeafg","abaf","dgdfdagagbd","gddcacg","gbfff","fcddcfdeaddebdbeffeeaacbbe","feffeccbgcadfffge","gfgbagfae","gfceaeabbgebaedafacbg","gfcbgccgd","deggbcc","gdcb","adcdffbebccbfdbacaagdaacdg","bbadcbgffgaaeecfagbfcf","adffcgeedfcafcebagdfdaagd","cfefc","efcc","eadgdbfggbfafabaa","gffdbcbcbbece","cgfccdbfffef","abcgbcbfcebeg","dega","fcecfeadaf","eefcfafecabgeedgae","bcagdcfgggcg","adcgbabcebcfaeacgg","babgbdbgbgb","eabdbacacdddd","fcgabbbgadgeceefdgedbdbbg","efc","bbbgacfbdffbgbe","feccbdecaggad","ebadefcfcbgbcbafgbfebf","bcadaeeaeceefgcgbcb","gcbceg","ffcaecgfebgeefegdeceefgge","abagd","fbdbedd","gac","babafgdfdggfgcdfdeb","fgbgcgcafacfbd","gc","ffecccgcgfbgdgedbefgcb","cfd","egfgfagecbaacaadfdf","faebcffaee","gbfcb","bacbgddcfbegbdacaggag","egfgcacgggecdgbegaeg","feafadgfcgegbeccbfcfefabb","dcbga","bbeeegfgedfd","bacdcg","aebgdcgdebcf","dbbaefcdfcadacebddfbcgg","egfbggabgadcdffafdaeebgdc","eadgbeccbgdffffcgfedfbbdbf","fbaabcadgebgebbacfg","eafdefaaacfbgggafbfb","febf","fbdfedcgaagaegdedgebedecg","aeecaegf","aeeff","daeccfeaabfabe","afcbdgge","agebffcbbcccaccf","bfddagefagbbaaeeadc","feagagebgg","aacgcagbcfceacdbfdedefgga","egaffdbg","edfdcfbeecgbbbdegdcegff","cac","agcbfbcafaeccfcdfdgg","ebedbbcga","fdbgge","caceagefebcggfffdfabegg","afbbagdeeaccgeedebdaeca","faeeddgfddddfddebgcfebaf","dbfedfdcdgcdbcb","dfcg","cg","ddagebcacadafa","baagcccfdfcecaabdcbbea","daefbfdgbeadbfgbade","bdfbddecfeebccbdfbfe","egcbddfddebfgefaacbcc","eab","dedcbgcd","bgggdeegdedfcecbbfgc","bbcggfeggcbfgaecgacbc","bcefeedaadgccg","ggffddegcdcgbfgadfgfbdagcg","dedbfbbgefgbacgbg","cbeeffefaeadgfebgecgaea","gfafgbf","bbaccgfagd","ddacbdegcdcdf","eafabfdccdec","adaaddbfaddcgeddgab","dcdcddbdgfcefbefedabe","egbbagadcecacdbgbccecfg","abfb","eegdbdga","ddcbffegdffga","cfab","bc","bac","aaeadfcgaeaecfdbfdadaf","gbgaa","cfcgceeabefcefdadbac","ffddddfgaddbcdfg","fgedabedegaaddea","gfefdfgfeddedc","cddbgbgbacfgb","edeedgeddadeecgd","eagbgggadgbgbfdcaccb","gadggdedfbgfgbfbffaadcccb","bddecffdffbbecdebgfdegc","baeaff","fcgba","bd","acabe","dceegeefbgbga","dgbff","ceegcabefecabggdbdbbg","cfecdffeggecdbb","dbff","fea","aegdbcbbbebdabbde","gf","eddafcfbaabfcgfaebcdfa","acdfcbdg","febagcdbfcedd","eebdfadbeaedadddgbaebeegfd","bbfcfbbedbbd","agecfeggedgafa","edbcgdcdebbfccaca","ffegcaggegeggcdegbgbgfb","bfbfacdgffgbbedcafdcdcfga","gbbfbeffegbaaf","gggbgfeddgcbfceeb","effgbbacbafgagedfe","gbdaeaaeg","fe","cddegcgbfggbfb","bfc","bcafcfgcfbeedafafecdgfc","eefeefcbedegaggb","dabafddcdfbdfgdcdabbdcafbga","bbdgbcdedgbecfbcacaafca","fcbedfbgcaffceeffbebcfbbf","bdecgfccedabd","cgfcdbgecbg","egdfada","fcgeceegac","bebged","cbefbcafdccffgdefcd","cd","cdcgafefdfgggfadccffdfg","aa","bcffaccaf","fdbfgcdfcg","dfaafffbdfgdbcebcfbeddgd","aaggcfbaddfcfa","abgfgagaebadec","adegcbd","gbbdebebfd","cdbbcecefagfffecdagded","fedcbcfbbdadceacc","gdfdccaadga","ffbeafgecbcfaddcefgee","efgdgdbcgcffb","bccgcgb","fgfdcacbafedg","eeegccbd","cgad","adffdegdaefcbcegafdbd","cebgadbfgg","babbcfecd","adaabfefaacfe","gbcbgebdefcedefdccadga","dbbfdccccbcbefffebcegefefca","geacdeefaagac","ccddgggdfbcgbcaedbf","fccdbgfdege","deebaedabcgdfefdacae","abaebbcaefcgdedabf","daccdaagdfg","fggdf","adagfbceabdafgegccd","ffdagbefbddafffdbeeecgd","gefgag"};
	vector<string> words;
	for(int i = 0; i < sizeof(strArr)/sizeof(strArr[0]); i++) 
		words.push_back(strArr[i]);
	return maxProduct(words);
}