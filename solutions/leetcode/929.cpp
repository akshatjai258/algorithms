class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> unique_emails;
        

        for (int i = 0; i < emails.size(); i++) {
            int at_position = emails[i].find("@");
            string local_name = emails[i].substr(0, at_position);
            string domain_name = emails[i].substr(at_position);
            
            // create if it has +, do the substring accordingly 
            
            if (find(local_name.begin(), local_name.end(), '+') != local_name.end()) {
                int plus_position = local_name.find("+");
                local_name = local_name.substr(0, plus_position);
                
            }
                        
            // filter out the dots in local_name
            local_name.erase(remove(local_name.begin(), local_name.end(), '.'), local_name.end());
            
            string email = local_name + domain_name;
            unique_emails.insert(email);            
            
        }

        
        return unique_emails.size();
        
    }
};