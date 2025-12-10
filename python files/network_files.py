import json

# Load JSON file
with open("ad_data.json", "r") as f:
    campaigns = json.load(f)

# Compute CPC per campaign (avoid divide-by-zero errors)
for campaign in campaigns:
    clicks = campaign["clicks"]
    campaign["CPC"] = campaign["budget"] / clicks if clicks > 0 else float("inf")

# Sort by CPC and take top 3
top_3 = sorted(campaigns, key=lambda c: c["CPC"])[:3]

# Output results
for c in top_3:
    print(f"{c['campaign_id']}: {c['CPC']:.2f}")
