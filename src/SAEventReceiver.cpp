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


void SAEventReceiver::saecreate(name author, name category, name owner, string idata, string mdata, uint64_t assetid, bool requireclaim)
{
	print_f("Asset created. Owner: %, assetid: % \n", owner, assetid);
}

void SAEventReceiver::saetransfer(name author, name from, name to, vector<uint64_t>& assetids, string memo)
{
	for (size_t i = 0; i < assetids.size(); i++) {
		print_f("Asset transfered. From % to %; assetid: % ; memo: % \n", from, to, assetids[i], memo);
	}
}

void SAEventReceiver::saeburn(name author, name owner, vector<uint64_t>& assetids, string memo)
{
	for (size_t i = 0; i < assetids.size(); i++) {
		print_f("Asset burned. assetid: % ; memo: % \n",  assetids[i], memo);
	}
}

void SAEventReceiver::saechauthor(name author, name newauthor, name owner, map< uint64_t, name >& assetids, string memo)
{
	auto assetidsIt = assetids.begin();
	while (assetidsIt != assetids.end()) {
		uint64_t keyid = (*assetidsIt).first;
		print_f("Asset claimed. From: %, assetid: % \n", assetids[keyid], keyid);

		assetidsIt++;
	}
}

void SAEventReceiver::saeclaim(name author, name claimer, map< uint64_t, name >& assetids)
{
	auto assetidsIt = assetids.begin();
	while (assetidsIt != assetids.end()) {
		uint64_t keyid = (*assetidsIt).first;
		print_f("Asset claimed. From: %, assetid: % \n", assetids[keyid], keyid);

		assetidsIt++;
	}
}

ACTION SAEventReceiver::hi() {
	print("\n hi");
}
