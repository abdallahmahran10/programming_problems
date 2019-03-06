package com.mahran;

import java.util.*;

class NumUniqueEmails {
	int numUniqueEmails(String[] emails) {
		Set<String> uniqueEmails = new HashSet<>();
		for (String email : emails) {
			String localName = getLocalName(email);
			String domainName = getDomainName(email);
			uniqueEmails.add(localName + "@" + domainName);
		}
		return uniqueEmails.size();
    }

	private String getDomainName(String email) {
		return email.substring(email.indexOf('@')+1);
	}

	private String getLocalName(String email) {
		String receivingEmail = "";
		for (int i=0; i < email.length(); i++) {
			if (email.charAt(i) == '.') {
				continue;
			}
			if (email.charAt(i) == '+') {
				break;
			}
			if (email.charAt(i) == '@') {
				break;
			}
			receivingEmail += email.charAt(i);
		}
		return receivingEmail;
	}
}
