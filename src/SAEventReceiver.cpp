/**
 *  SimpleAssets - Event Receiver Example (Digital Assets)
 *  (C) 2019 by CryptoLions [ https://CryptoLions.io ]
 *
 *  SimpleAssets - A simple standard for digital assets (ie. Non-Fungible Tokens) for EOSIO blockchains
 *
 *    WebSite:        https://simpleassets.io
 *    GitHub:         https://github.com/CryptoLions/SimpleAssets 
 *    Presentation:   https://medium.com/@cryptolions/introducing-simple-assets-b4e17caafaa4
 * 
 */
 
#include <SAEventReceiver.hpp>


ACTION SAEventReceiver::saecreate( name owner, uint64_t assetid ) {
	print_f("Asset created. Owner: %, assetid: % \n", owner, assetid);
}


ACTION SAEventReceiver::saetransfer( name from, name to, std::vector<uint64_t>& assetids, std::string memo ) {

	for( size_t i = 0; i < assetids.size(); i++ ) {
		print_f("Asset transfered. From % to %; assetid: % ; memo: % \n", from, to, assetids[i], memo);
	}
}


ACTION SAEventReceiver::saeclaim( name who, std::map< uint64_t, name>& assetids ) {

	auto assetidsIt = assetids.begin(); 
	while(assetidsIt != assetids.end() ) {
		uint64_t keyid = (*assetidsIt).first; 
		print_f("Asset claimed. From: %, Who: %, assetid: % \n", assetids[keyid], who, keyid);

		assetidsIt++;
	}
	
}

ACTION SAEventReceiver::saeburn( name who, std::vector<uint64_t>& assetids, std::string memo ) {
	
	for( size_t i = 0; i < assetids.size(); i++ ) {
		print_f("Asset burned. Who: %, assetid: % ; memo: % \n", who, assetids[i], memo);
	}
}

EOSIO_DISPATCH( SAEventReceiver, (saecreate)(saetransfer)(saeclaim)(saeburn) )